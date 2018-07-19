#include "merger.h"

#include <algorithm>
#include <exceptions.h>
#include <iostream>


QString Merger::getSaveFileName() const
{
    return saveFileName;
}

void Merger::setSaveFileName(const QString &value)
{
    saveFileName = value;
}

Merger::TraceSortType Merger::getTraceSortType() const
{
    return traceSortType;
}

void Merger::setTraceSortType(const TraceSortType &value)
{
    traceSortType = value;
    switch(traceSortType){
    case Time:
        compareTrace = &Merger::compareTraceDataByTime;
        compareFile = &Merger::compareFileDataByTime;
        break;
    case LineNumberSeq:
        compareTrace = &Merger::compareTraceDataByLine;
        compareFile = &Merger::compareFileDataByLine;
        break;
    case SegyFileSeq:
    case None:
        compareTrace = &Merger::compareTraceDataBySegySeq;
        compareFile = &Merger::compareFileDataBySegySeq;
        break;
    default:
        compareTrace = &Merger::compareTraceDataBySegySeq;
        compareFile = &Merger::compareFileDataBySegySeq;
    }
}
Merger::Merger(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 400; i ++){
        binaryHeader[i] = 0;
    }
    for( int i = 1; i <= 40; i++){
        textualHeader[((i-1)*80)] = 'C';
        if(i <= 9){
            textualHeader[((i-1)*80)+ 1] = ' ';
            textualHeader[((i-1)*80)+2] = '0' + i;
        }
        else if (i <= 19){
            textualHeader[((i-1)*80)+ 1] = '1';
            textualHeader[((i-1)*80)+2] = '0' + i;
        }
        else if (i <= 29){
            textualHeader[((i-1)*80)+ 1] = '2';
            textualHeader[((i-1)*80)+2] = '0' + i;
        }
        else if (i <= 39){
            textualHeader[((i-1)*80)+ 1] = '3';
            textualHeader[((i-1)*80)+2] = '0' + i;
        }
        else {
            textualHeader[((i-1)*80)+ 1] = '4';
            textualHeader[((i-1)*80)+2] = '0';
        }
        textualHeader[((i-1)*80)+ 3] = ' ';
    }
    success = true;
}

void Merger::addFile(QString loc, bool isBE){
    FileData *fileData = new FileData;
    fileData->location = loc;
    fileData->BE = isBE;
    fileData->name = loc.right(loc.size() - loc.lastIndexOf('/') - 1);
    files.push_back(fileData);
}

void Merger::removeFile(int index){
    FileData *fileData = *((files.begin()+index).base());
    files.erase(files.begin()+index);
    delete fileData;
}

FileData* Merger::getFile(int index){
    return *((files.begin()+index).base());
}

void Merger::initializeFiles(){
    FileData *fileData;
    for(unsigned int i = 0; i < files.size() ; i++){
        fileData = files.at(i);
        if(fileData->BE){
            fileData->sf = new SegyFileBigEndian(fileData->location.toStdString());
            fileData->lineNumber = fileData->sf->getBinaryHeader(1);
            fileData->reelNumber = fileData->sf->getBinaryHeader(2);
        }else{
            fileData->sf = new SegyFileLittleEndian(fileData->location.toStdString());
            fileData->lineNumber = fileData->sf->getBinaryHeader(1);
            fileData->reelNumber = fileData->sf->getBinaryHeader(2);
        }
    }
}

void Merger::setBinaryHeader(int value, int index){
    int startingByte = SegyFile::headerArrayInfo[index].startOffset - 3201;
    int numOfBytes = SegyFile::headerArrayInfo[index].numOfBytes;
    if( numOfBytes == 2){
        binaryHeader[startingByte] =(unsigned char) ((value&0xFF00)>>8);
        binaryHeader[startingByte+1] =(unsigned char) ((value&0xFF));
    }else if (numOfBytes == 4){
        binaryHeader[startingByte] =(unsigned char) ((value&0xFF000000)>>24);
        binaryHeader[startingByte+1] =(unsigned char) ((value&0xFF0000)>>16);
        binaryHeader[startingByte+2] =(unsigned char) ((value&0xFF00)>>8);
        binaryHeader[startingByte+3] =(unsigned char) ((value&0xFF));
    }
}

void Merger::setTextualHeaderLine(int lineIndex, QString line){
    unsigned char *d;
    d = (unsigned char*)line.toStdString().data();
    int i;
    for( i = 0 ; i < line.size() ; i++){
        textualHeader[(lineIndex*80) + 4 + i] = *(d+i);
    }
    for(;i<76; i++){
        textualHeader[(lineIndex*80) + 4 + i] = ' ';
    }
    //cout<<line.toStdString()<<endl;
}

void Merger::writeBinaryHeader(){
    emit independentLegProgress(0);
    saveFile->write((char*)binaryHeader,400);
    emit independentLegProgress(100);
}

void Merger::writeTextualHeader(){
    float progress = 0;
    float progressStep = 100/40;
//    string s;
//    char *data = (char *)textualHeader;
//    for(int i = 0; i< 40; i++){
//        emit independentLegProgress(progress);
//        saveFile->write(data,80);
//        progress+=progressStep;
//        data+=80;
//    }
    for(int i = 0; i < 3200; i++){
        saveFile->put(textualHeader[i]);
        //cout<<textualHeader[i];
    }
    emit independentLegProgress(100);
}

void Merger::writeTraces(){
    //now that all the traces are sorted for each of the segyfiles
    //task reamins only to pick the smallest or preceding trace
    //from the files and write it first onto the new file
    //in this we will also change its segyseqheader to a new one.
    //for this task, we have three functions
    //--compareByTime
    //--compareByLine
    //--compareBySegySeq
    progress = 0.0f;

    FileData **filedata = files.data();

    int sumNumTraces = 0;
    for(unsigned int i = 0; i < files.size(); i++){
        //filedata[i]=files.at(i);
        sumNumTraces += filedata[i]->sf->getNumOfTraces();
    }
    progressStep = 100.0f/sumNumTraces;
    //here we the head trace of each trace list of each segy file
    //these have already been sorted.
    //thus task remains only to find the smallest among the heads.
//    FileData *filedata[files.size()];
//    for(int i = 0; i < files.size(); i++){
//        filedata[i] = files.at(i);
//    }
    //we deem the first filedata as the smallest in each iteration
    //then compare it with all the remaining filedata objects.
    //--1st iteration of Selection Sort.

    int traceSeq = 1; //to write sequence number in segy file for the new file
    int headIndices[files.size()]; //to store the indices of heads of all the trace lists.
    int traceIndexLimits[files.size()]; //to store the number of traces in each segyfile
    //bool tracesRemain[files.size()]; //to store if the trace list has ended
    //int traceListsRemaining = 0; //to store how many lists are remaining
    int totalTracesRemaining = 0; //to store the remaining traces;
    int cstd = 0;// [C]urrent index of [STD]
    for( unsigned int i = 0; i < files.size(); i++){
        headIndices[i] = 0;
        traceIndexLimits[i] = filedata[i]->sf->getNumOfTraces();
        totalTracesRemaining+=traceIndexLimits[i];
        //if(traceIndexLimits[i] > 0){
            //tracesRemain[i] = true;
            //traceListsRemaining++;
        //}
        //else tracesRemain[i] = false;
    }

    char *buffer;
    //char zeroBuffer[8] = {0 ,0, 0, 0, 0, 0, 0, 0};
    Trace *t;
    TraceData *std = 0; //to keep reference of the currently [S]mallest[T]race[D]ata object.
    //we count the remaining trace lists.
    //to check whether to iterate again.
    unsigned int f;
    while(totalTracesRemaining > 0/*checkAnyTrue(tracesRemain, traceListsRemaining)*/){
        emit independentLegProgress(progress);
        for(f = 0 /*file index*/; f < files.size(); f++){
            //checking if the file has remaining traces
            if(headIndices[f] < traceIndexLimits[f]){
                //traces remaining.
                if(std == 0){
                    //no std yet
                    std = &(filedata[f]->traces[headIndices[f]]);
                    cstd = f;
                }else{
                    if(compareTrace(filedata[f]->traces[headIndices[f]], *std)){
                        //current will precede
                        std = &(filedata[f]->traces[headIndices[f]]);
                        cstd = f;
                    }
                }
            }//else{
                //no traces remain in current list.
                //tracesRemain[f] = false;
                //traceListsRemaining--;
            //}
        }
        //std is a cstd file.
        //cout<<"cstd "<<cstd<<" headIndex "<< headIndices[cstd]<<" traceindexlimits "<<traceIndexLimits[cstd]<<endl;
        t = filedata[cstd]->traces[headIndices[cstd]].t;

        //increase file f's headIndex
        headIndices[cstd]++;
        //now that we have the trace, we write it onto the file.

        //cout<<saveFile->tellp()<<endl;
        //copy the first header onto file
        int header = t->getBinaryHeader(0);
        unsigned char c = (header&0xFF000000)>>24;
        saveFile->put(c);
        c = (header&0xFF0000)>>16;
        saveFile->put(c);
        c = (header&0xFF00)>>8;
        saveFile->put(c);
        c = (header&0xFF);
        saveFile->put(c);
        //copy the new file sequnce number
        c = (traceSeq&0xFF000000)>>24;
        saveFile->put(c);
        c = (traceSeq&0xFF0000)>>16;
        saveFile->put(c);
        c = (traceSeq&0xFF00)>>8;
        saveFile->put(c);
        c = (traceSeq&0xFF);
        saveFile->put(c);
        //writing the rest trace headers (till 232 bye offset) from 3rd header (9 byte offset)

        for( int i = 2; i < 89; i++){
            //int startByte = Trace::getBinaryHeaderInfo(i)->startOffset;
            int numOfByte = Trace::getBinaryHeaderInfo(i)->numOfBytes;
            header = t->getBinaryHeader(i);
            if(numOfByte == 4){
                c = (header&0xFF000000)>>24;
                saveFile->put(c);
                c = (header&0xFF0000)>>16;
                saveFile->put(c);
                c = (header&0xFF00)>>8;
                saveFile->put(c);
                c = (header&0xFF);
                saveFile->put(c);
            }else {
                c = (header&0xFF00)>>8;
                saveFile->put(c);
                c = (header&0xFF);
                saveFile->put(c);
            }
        }
        //filling the remaining bytes (8) with zeroes
        c = 0;
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);
        saveFile->put(c);


        //writing the trace sample data onto file.
        t->resetIndex();
        int bytesPerSample = t->getBytesPerSample();
        for( int i = 0 ; i < t->getNumOfSamples(); i++){
           buffer = t->getNextSampleRaw(true);
           saveFile->write(buffer, bytesPerSample);
           delete buffer;
        }
        std = 0;

        totalTracesRemaining--;
        traceSeq++;
        progress+=progressStep;
    }
    emit independentLegProgress(100);//100 %  now
}

void Merger::readTraces(){
    progress = 0;

    FileData *filedata;

    int sumNumTraces = 0;
    for(unsigned int i = 0; i < files.size(); i++){
        filedata=files.at(i);
        sumNumTraces += filedata->sf->getNumOfTraces();
    }
    progressStep = 100.0f/sumNumTraces;

    //reading traces from each segyFile to their coresponding trace lists
    //also calculating least time of the segy files
    struct TimeStruct leastTime;
    for(unsigned int i = 0; i < files.size(); i++){
        filedata = files.at(i);
        filedata->traces = new TraceData[filedata->sf->getNumOfTraces()];
        leastTime.year = 5000;
        for(int j = 0 ; j < filedata->sf->getNumOfTraces(); j++){
            emit independentLegProgress(progress);
            filedata->traces[j].seqSegyFile = j;
            filedata->traces[j].t = filedata->sf->getTraceAt(j);
            filedata->traces[j].time.year = filedata->traces[j].t->getBinaryHeader(59);
            if(filedata->traces[j].time.year<100) filedata->traces[j].time.year+=1900;
            filedata->traces[j].time.day = filedata->traces[j].t->getBinaryHeader(60);
            filedata->traces[j].time.hour = filedata->traces[j].t->getBinaryHeader(61);
            filedata->traces[j].time.min = filedata->traces[j].t->getBinaryHeader(62);
            filedata->traces[j].time.sec = filedata->traces[j].t->getBinaryHeader(63);
            if( filedata->traces[j].time < leastTime)  leastTime = filedata->traces[j].time;
            filedata->traces[j].seqLine = filedata->traces[j].t->getBinaryHeader(0);
            progress+=progressStep;
        }
        filedata->leastTime = leastTime;
    }
    emit independentLegProgress(progress);
}

void Merger::sortTraces(){

    //sorts traces separately in each segy file.
    //according to the sort type
    progress = 0.0f;
    progressStep = 100/(files.size()+1);
    emit independentLegProgress(progress);
    std::stable_sort(files.begin(), files.end(), compareFile);
    progress+=progressStep;
    FileData *filedata;
    for(unsigned int i = 0; i <  files.size(); i++){
        emit independentLegProgress(progress);
        filedata = files.at(i);
        std::stable_sort(&filedata->traces[0], &filedata->traces[filedata->sf->getNumOfTraces()],compareTrace);
        progress+=progressStep;
    }
    emit independentLegProgress(100);//100 %  now
}

void Merger::createFile(){

    emit independentLegProgress(0);
    saveFile = new fstream(saveFileName.toStdString().data(),ios_base::out | ios_base::trunc );
    emit independentLegProgress(50);
    if(saveFile->is_open()){
        saveFile->seekp(0, ios_base::beg);
        emit independentLegProgress(100);
    }else{
        throw new BadFileException();
    }
}


bool Merger::getSuccess() const
{
    return success;
}

void Merger::setSuccess(bool value)
{
    success = value;
}
bool Merger::checkAnyTrue(bool *arr, int size){
    bool ans = false;
    for(int i = 0 ;i < size ; i++){
        ans|=arr[i];
    }
    return ans;
}

void Merger::setFileBE(int index, bool BE){
    FileData *filedata = files.at(index);
    filedata->BE = BE;
}

int Merger::getNumOfFiles(){
    return files.size();
}

QString Merger::getFileNameAt(int index){
    FileData *filedata = files.at(index);
    return filedata->name;
}

void Merger::setRequiredHeader(){
    FileData *filedata = files.at(0);
    setBinaryHeader(filedata->sf->getDataEncodedIn(),9);
    setBinaryHeader(0,27);
    setBinaryHeader(0,28);
    setBinaryHeader(0,29);
    setBinaryHeader(filedata->sf->getSampleIntervalOfDataTraces(),5);
    setBinaryHeader(filedata->sf->getNumOfSamplesPerDataTrace(),7);
}

void Merger::finish(){
    if(saveFile->is_open()){
        saveFile->close();
    }
}

void Merger::lastPageRequest(){
    emit lastPage();
}
