#include "segyfilelittleendian.h"
#include "tracelittleendian.h"
#include <exceptions.h>
#include <list>
#include <sstream>
#include <iostream>

using namespace std;

SegyFileLittleEndian::SegyFileLittleEndian(string fileName) : SegyFile(fileName)
{
    //copying the file to a temporary file first
    //fstream in (originalFileName.data(), ios_base::in | ios_base::binary);
    originalFile = new fstream(originalFileName.data(),ios_base::in | ios_base::out | ios_base::binary);
    if(originalFile->is_open()){
        read();
    }else {
        BadFileException bfe;
        throw bfe;
    }
}

int SegyFileLittleEndian::getBinaryHeader(int startingByte, int numOfBytes, bool offsetted){
    int offset;
    unsigned int ans;
    if(offsetted) offset = 3200; else offset = 0;
    originalFile->seekg(offset + startingByte - 1, ios_base::beg);
    ans = 0;
    if(numOfBytes == 2){
        ans+=originalFile->get();
        ans+=(((unsigned int)originalFile->get())<<8);
        int check = 1u<<15;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }else if(numOfBytes == 4){
        ans+=(unsigned int)originalFile->get();
        ans+=(((unsigned int)originalFile->get())<<8);
        ans+=(((unsigned int)originalFile->get())<<16);
        ans+=(((unsigned int)originalFile->get())<<24);
        int check = 1u<<31;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }
    return (int)ans;
}

void SegyFileLittleEndian::setBinaryHeader(int value, int startingByte, int numOfBytes, bool offsetted){
    int offset = offsetted?3200:0;
    originalFile->seekp(offset+startingByte - 1);
    if(numOfBytes == 2){
        originalFile->put((char)(value&0xFF));
        originalFile->put((char)((value&0xFF00)>>8));
    }else if(numOfBytes == 4){
        originalFile->put((char)(value&0xFF));
        originalFile->put((char)((value&0xFF00)>>8));
        originalFile->put((char)((value&0xFF0000)>>16));
        originalFile->put((char)((value&0xFF000000)>>24));
    }
}

Trace* SegyFileLittleEndian::getTraceAt(int index){
    //delete trace;
    trace = new TraceLittleEndian(originalFile,dataEncodedIn,traceBeginsAt+traceOffsets[index], numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);
    return trace;
}

void SegyFileLittleEndian::readTraces(){
    //reading traces now
    if(fixedLengthTraces){
        int size = 240 + (numOfSamplesPerDataTrace * bytesPerSample);
        originalFile->seekg(0,ios_base::end);
        int end = originalFile->tellg();
        numOfTraces = (end-traceBeginsAt) / size;
        traceOffsets = new int[numOfTraces];
        for(int i = 0; i<numOfTraces;i++){
            traceOffsets[i] = size*i;
        }
    }else{
        list<int> tO;
        numOfTraces = 0;
        int seek = 3601;
        originalFile->seekg(0,ios_base::end);
        int end = originalFile->tellg();
        while(seek < end){            tO.push_back(seek-3601);            trace = new TraceLittleEndian(originalFile,dataEncodedIn,seek,numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);            numOfTraces++;            seek+=trace->getSize();            /*delete trace;*/        }
        traceOffsets = new int[numOfTraces];
        int i = 0;
        for(list<int>::iterator it = tO.begin(); it != tO.end(); it++){
            traceOffsets[i] = *it;
            i++;
        }
    }
    //cout<<"Trace Begins At="<<traceBeginsAt<<endl;
    trace = new TraceLittleEndian(originalFile,dataEncodedIn,traceBeginsAt,numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);
}

SegyFileLittleEndian::~SegyFileLittleEndian(){
    originalFile->close();
    //std::remove(temporaryFileName.data());
    //delete trace;
    delete[] traceOffsets;
}

void SegyFileLittleEndian::convertToBigEndian(string newFileName){
    fstream *out = new fstream(newFileName.data(),ios_base::out | ios_base::trunc | ios_base::binary);
    if(out->is_open()){
        char *buffer;
        //writing TextHeader to new file.
        originalFile->seekg(0,ios_base::beg);
        buffer = new char[3201];
        originalFile->read(buffer,3200);
        buffer[3200] = '\0';
        out->write(buffer, 3200);
        delete[] buffer;
        //writing BinaryHeaders to new file.
        SegyFile::HeaderInfo *hi;
        int header;
        //the firsst 27 contiguous headers.
        for(int i = 0; i < 27; i++){
            hi = SegyFile::getBinaryHeaderInfo(i);
            header = SegyFile::getBinaryHeader(i);
            if(hi->numOfBytes == 2){
                out->put((char)((header & 0xFF00)>>8));
                out->put((char)((header & 0xFF)));
            }else{
                out->put((char)((header & 0xFF000000)>>24));
                out->put((char)((header & 0xFF0000)>>16));
                out->put((char)((header & 0xFF00)>>8));
                out->put((char)((header & 0xFF)));
            }
        }
        //copying later 140 bytes as is.
        buffer = new char[240];
        originalFile->read(buffer, 240);
        out->write(buffer, 240);
        delete[] buffer;
        //the last 3 contiguos headers
        for(int i = 27; i < 30; i++){
            hi = getBinaryHeaderInfo(i);
            header = SegyFile::getBinaryHeader(i);
            if(hi->numOfBytes == 2){
                out->put((char)((header & 0xFF00)>>8));
                out->put((char)((header & 0xFF)));
            }else{
                out->put((char)((header & 0xFF000000)>>24));
                out->put((char)((header & 0xFF0000)>>16));
                out->put((char)((header & 0xFF00)>>8));
                out->put((char)((header & 0xFF)));
            }
        }
        //copying reamining 94 bytes as is.
        buffer = new char[94];
        originalFile->read(buffer, 94);
        out->write(buffer, 94);
        delete[] buffer;

        //copying extended headers
        if(numOfExtendedHeaders== -1){
            //not copying it
        }else if(numOfExtendedHeaders > 0){
            int size = 3200 * numOfExtendedHeaders;
            buffer = new char[size];
            originalFile->read(buffer, size);
            out->write(buffer, size);
            delete[] buffer;
        }

        cout<<"before trace start\tout:"<<out->tellp()<<"\toriginal:"<<originalFile->tellg()<<endl;

        //copying traces
        originalFile->seekp(3600,ios_base::beg);
        Trace *t;
        Trace::HeaderInfo *thi;
        for(int i = 0; i< numOfTraces; i++){
            t = getTraceAt(i);
            //copying binary headers
            for(int i = 0; i < 89; i++){
                thi = Trace::getBinaryHeaderInfo(i);
                header = t->getBinaryHeader(i);
                if(thi->numOfBytes == 2){
                    out->put((char)((header & 0xFF00)>>8));
                    out->put((char)((header & 0xFF)));
                }else{
                    out->put((char)((header & 0xFF000000)>>24));
                    out->put((char)((header & 0xFF0000)>>16));
                    out->put((char)((header & 0xFF00)>>8));
                    out->put((char)((header & 0xFF)));
                }
            }
            //copying remaining 8 bytes as is.
            buffer = new char[8];
            originalFile->read(buffer, 8);
            out->write(buffer, 8);
            delete[] buffer;

            //copying traceData
            t->resetIndex();
            char *data;
            for(int i = 0; i < t->getNumOfSamples(); i++){
               data = t->getNextSampleRaw(true);
               out->write(data, t->getBytesPerSample());
               delete[] data;
            }
        }
        cout<<"after trace start\tout:"<<out->tellp()<<"\toriginal:"<<originalFile->tellg()<<endl;
    }
    else{
        throw new BadFileException();
    }
}
