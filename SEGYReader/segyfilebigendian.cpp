#include "segyfilebigendian.h"
#include <list>
#include <traceRevised.h>
#include <tracebigendian.h>
#include <exceptions.h>
#include <iostream>

using namespace std;

SegyFileBigEndian::SegyFileBigEndian(string fileName):SegyFile(fileName)
{
    originalFile = new fstream(originalFileName.data(),ios_base::in | ios_base::out | ios_base::binary);
    if(originalFile->is_open()){
        read();
    }else {
        BadFileException bfe;
        throw bfe;
    }
}
int SegyFileBigEndian::getBinaryHeader(int startingByte, int numOfBytes, bool offsetted){
        int offset;
        int ans;
        if(offsetted) offset = 3200; else offset = 0;
        originalFile->seekg(offset + startingByte - 1, ios_base::beg);
        ans = 0;
        if(numOfBytes == 2){
            ans+=originalFile->get();
            ans <<=8;
            ans+=originalFile->get();
            int check = 1u<<15;
            if((check&ans) > 0){
                ans|=~(check-1);
            }
        }else if(numOfBytes == 4){
            ans+=(unsigned int)originalFile->get();
            ans <<=8;
            ans+=(unsigned int)originalFile->get();
            ans <<=8;
            ans+=(unsigned int)originalFile->get();
            ans <<=8;
            ans+=(unsigned int)originalFile->get();
            int check = 1u<<31;
            if((check&ans) > 0){
                ans|=~(check-1);
            }
        }
        return ans;
}

void SegyFileBigEndian::setBinaryHeader(int value, int startingByte, int numOfBytes, bool offsetted){
    int offset = offsetted?3200:0;
    originalFile->seekp(offset+startingByte - 1);
    if(numOfBytes == 2){
        originalFile->put((char)((value&0xFF00)>>8));
        originalFile->put((char)(value&0xFF));
    }else if(numOfBytes == 4){
        originalFile->put((char)((value&0xFF000000)>>24));
        originalFile->put((char)((value&0xFF0000)>>16));
        originalFile->put((char)((value&0xFF00)>>8));
        originalFile->put((char)(value&0xFF));
    }
}

void SegyFileBigEndian::readTraces(){
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
        //if(numOfSamplesPerDataTrace = 0) numOfSamplesPerDataTrace = -1;
        while(seek < end){            tO.push_back(seek-3601);            trace = new TraceBigEndian(originalFile,dataEncodedIn,seek,numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);            numOfTraces++;            seek+=trace->getSize();            /*delete trace;*/        }
        traceOffsets = new int[numOfTraces];
        int i = 0;
        for(list<int>::iterator it = tO.begin(); it != tO.end(); it++){
            traceOffsets[i] = *it;
            i++;
        }
        //cout<<tO.size()<<endl;
    }
    //cout<<"Trace Begins At="<<traceBeginsAt<<endl;
    trace = new TraceBigEndian(originalFile,dataEncodedIn,traceBeginsAt,numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);
}

Trace* SegyFileBigEndian::getTraceAt(int index){
    //delete trace;
    trace = new TraceBigEndian(originalFile,dataEncodedIn,traceBeginsAt+traceOffsets[index], numOfSamplesPerDataTrace, sampleIntervalOfDataTraces);
    return trace;
}

SegyFileBigEndian::~SegyFileBigEndian(){
    originalFile->close();
    //std::remove(temporaryFileName.data());
    delete trace;
    delete[] traceOffsets;
}

void SegyFileBigEndian::convertToBigEndian(string fileName){
    //try to find a workaround
}
