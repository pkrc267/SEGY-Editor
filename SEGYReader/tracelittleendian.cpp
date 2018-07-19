#include "tracelittleendian.h"
#include <cmath>

using namespace std;

TraceLittleEndian::TraceLittleEndian(fstream *_file,  int de, int seek, int _numOfSamples, int _sampleInterval)
{
    file = _file;
    index = 0;
    startsAt = seek - 1;

    setDE(de);

    if(_numOfSamples == -1){
        numOfSamples = getBinaryHeader(115,2);
        sampleInterval = getBinaryHeader(117,2);
    }else {
        numOfSamples=_numOfSamples;
        sampleInterval = _sampleInterval;
    }

}

int TraceLittleEndian::getBinaryHeader(int startingByte, int numOfBytes){
    int ans;
    file->seekg(startsAt + startingByte-1, ios_base::beg);
    if(numOfBytes == 2){
        ans=file->get();
        ans+=(((unsigned int)file->get())<<8);
        int check = 1u<<15;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }else if(numOfBytes == 4){
        ans=((unsigned int)file->get());
        ans+=((unsigned int)file->get())<<8;
        ans+=((unsigned int)file->get())<<16;
        ans+=((unsigned int)file->get())<<24;
        int check = 1u<<31;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }
    return ans;
}

void TraceLittleEndian::setBinaryHeader(int value, int startingByte, int numOfBytes){
    file->seekp(startsAt+startingByte -1, ios_base::beg);
    if(numOfBytes == 2){
        file->put((char)(value&0xFF));
        file->put((char)((value&0xFF00)>>8));
    }else if(numOfBytes == 4){
        file->put((char)(value&0xFF));
        file->put((char)((value&0xFF00)>>8));
        file->put((char)((value&0xFF0000)>>16));
        file->put((char)((value&0xFF000000)>>24));
    }
}

double TraceLittleEndian::getSampleCode1(const char *data){
    int sign;
    int d = ((*data)) + ((*(data+1))<<8) + ((*(data+2))<<16) + ((*(data+3))<<24);
    if(((d & 0x80000000)>>31) == 1) sign = -1; else sign = 1;
    int exponent = ((d&0x7F000000)>>24) - 64;
    return (((d&0x00FFFFFE)>>1) / 8388608.0d) * pow(16.0d, exponent) * sign;
}

double TraceLittleEndian::getSampleCode2(const char *data){//4-byte two's complement
    int d = ((*data)) + ((*(data+1))<<8) + ((*(data+2))<<16) + ((*(data+3))<<24);
    int check = 0x80000000u;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

double TraceLittleEndian::getSampleCode3(const char *data){//2-byte two's complement
    int d=0;
    d = ((*data)) + ((*(data+1))<<8);
    int check = 0x8000u;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

double TraceLittleEndian::getSampleCode4(const char *data){//32-bit fixed point with gain
    int d = 0;
    d = ((*(data))<<8) + ((*(data+1)));
    int check = 0x8000u;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    int g = *(data+2);
    return pow((double) d, (double) g);
}

double TraceLittleEndian::getSampleCode5(const char *data){
    return (double) (*(float *)data);
}

double TraceLittleEndian::getSampleCode6(const char *data){
    return -1.0d;
}

double TraceLittleEndian::getSampleCode7(const char *data){
    return -1.0d;
}

double TraceLittleEndian::getSampleCode8(const char *data){
    int d = (*data);
    int check = 0x80u;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

char* TraceLittleEndian::getNextSampleRaw(bool asBE=false){
    if(index >= numOfSamples) {index = 0; file->seekg(startsAt + 240); }
    char *data = new char[bytesPerSample];
    file->read(data,bytesPerSample);
    index ++;
    if(!asBE){
        char t;
        t = *data;
        *data = *(data+3);
        *(data+3) = t;

        t=*(data+1);
        *(data+1) = *(data+2);
        *(data+2) = t;
    }
    return data;
}

void TraceLittleEndian::setDE(int de){
    switch(de){
        case 1: _getSample = &TraceLittleEndian::getSampleCode1;
            bytesPerSample = 4;
            break;
        case 2: _getSample = &TraceLittleEndian::getSampleCode2;
            bytesPerSample = 4;
            break;
        case 3: _getSample = &TraceLittleEndian::getSampleCode3;
            bytesPerSample = 2;
            break;
        case 4: _getSample = &TraceLittleEndian::getSampleCode4;
            bytesPerSample = 4;
            break;
        case 5: _getSample = &TraceLittleEndian::getSampleCode5;
            bytesPerSample = 4;
            break;
        case 0: _getSample = &TraceLittleEndian::getSampleCode6;
            bytesPerSample = 0;
            break;
        case 8: _getSample = &TraceLittleEndian::getSampleCode8;
            bytesPerSample = 1;
            break;
        default: _getSample=&TraceLittleEndian::getSampleCode1;
    }
}

double TraceLittleEndian::getSample(const char *d){
    return (this->*_getSample)(d);
}

TraceLittleEndian::~TraceLittleEndian(){}

void TraceLittleEndian::setNextSampleRaw(char *data){
    if(index >= numOfSamples) {index = 0; file->seekp(startsAt + 240); }
    file->write(data,bytesPerSample);
    index++;
}
