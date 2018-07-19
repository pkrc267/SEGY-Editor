#include "tracebigendian.h"

#include <cmath>
#include <iostream>

TraceBigEndian::TraceBigEndian(fstream *_file, int de, int seek, int _numOfSamples, int _sampleInterval):Trace()
{
    file = _file;
    index = 0;
    startsAt = seek - 1;
    //cout<<"startsAt:"<<startsAt<<endl;
    setDE(de);

    if(_numOfSamples == -1){
        numOfSamples = getBinaryHeader(115,2);
        sampleInterval = getBinaryHeader(117,2);
    }else {
        numOfSamples=_numOfSamples;
        sampleInterval = _sampleInterval;
    }
    //cout<<"numOfSamples:"<<numOfSamples<<endl;
}

double TraceBigEndian::getSampleCode1(const char *data){
    int sign;
    int d = ((*data)<<24) + ((*(data+1))<<16) + ((*(data+2))<<8) + ((*(data+3)));
    if(((d & 0x80000000)>>31) == 1) sign = -1; else sign = 1;
    int exponent = ((d&0x7F000000)>>24) - 64;
    return (((d&0x00FFFFFE)>>1) / 8388608.0d) * pow(16.0d, exponent) * sign;
}

double TraceBigEndian::getSampleCode2(const char *data){//4-byte two's complement
    int d = 0;
    d = ((*data)<<24) + ((*(data+1))<<16) + ((*(data+2))<<8) + ((*(data+3)));
    int check = 1u<<31;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

double TraceBigEndian::getSampleCode3(const char *data){//2-byte two's complement
    int d=0;
    d = ((*data)<<8) + (*(data+1));
    int check = 1u<<15;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

double TraceBigEndian::getSampleCode4(const char *data){//32-bit fixed point with gain
    int d = 0;
    d = ((*(data+2))<<8) + (*(data+3));
    int check = 1u<<15;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    int g = *(data+1);
    return pow((double) d, (double) g);
}

double TraceBigEndian::getSampleCode5(const char *data){
    return (double) (*(float *)data);
}

double TraceBigEndian::getSampleCode6(const char *data){
    return -1.0d;
}

double TraceBigEndian::getSampleCode7(const char *data){
    return -1.0d;
}

double TraceBigEndian::getSampleCode8(const char *data){
    int d = (*data);
    int check = 1u<<7;
    if((d & check) > 0){
        check = ~(check - 1);
        d|=check;
    }
    return (double) d;
}

int TraceBigEndian::getBinaryHeader(int startingByte, int numOfBytes){
    int ans;
    file->seekg(startsAt + startingByte-1, ios_base::beg);
    if(numOfBytes == 2){
        ans=file->get();
        ans <<=8;
        ans+=file->get();
        int check = 1u<<15;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }else if(numOfBytes == 4){
        ans=(unsigned int)file->get();
        ans <<=8;
        ans+=(unsigned int)file->get();
        ans <<=8;
        ans+=(unsigned int)file->get();
        ans <<=8;
        ans+=(unsigned int)file->get();
        int check = 1u<<31;
        if((check&ans) > 0){
            ans|=~(check-1);
        }
    }
    return ans;
}

void TraceBigEndian::setBinaryHeader(int value, int startingByte, int numOfBytes){
    cout<<"Set Trace Header!!! B"<<endl;
    file->seekp(startsAt+startingByte -1, ios_base::beg);
    if(numOfBytes == 2){
        file->put((char)((value&0xFF00)>>8));
        file->put((char)(value&0xFF));
    }else if(numOfBytes == 4){
        file->put((char)((value&0xFF000000)>>24));
        file->put((char)((value&0xFF0000)>>16));
        file->put((char)((value&0xFF00)>>8));
        file->put((char)(value&0xFF));
    }
    cout<<"Set Trace Header!!! A"<<endl;
}

double TraceBigEndian::getSample(const char * d){
    return (this->*_getSample)(d);
}

void TraceBigEndian::setNextSampleRaw(char *data){
    if(index >= numOfSamples) {index = 0; file->seekp(startsAt + 240); }
    file->write(data,bytesPerSample);
    index++;
}

char* TraceBigEndian::getNextSampleRaw(bool asBE=true){
    char *data = new char[bytesPerSample];
    if(index >= numOfSamples) {index = 0; file->seekg(startsAt + 240); }
    file->read(data,bytesPerSample);
    index ++;
    if(!asBE){
        char t;
        t = data[0];
        data[0] = data[3];
        data[3] = t;

        t=data[1];
        data[1] = data[2];
        data[2] = t;
    }
    return data;
}

void TraceBigEndian::setDE(int de){
    switch(de){
        case 1: _getSample = &TraceBigEndian::getSampleCode1;
            bytesPerSample = 4;
            break;
        case 2: _getSample = &TraceBigEndian::getSampleCode2;
            bytesPerSample = 4;
            break;
        case 3: _getSample = &TraceBigEndian::getSampleCode3;
            bytesPerSample = 2;
            break;
        case 4: _getSample = &TraceBigEndian::getSampleCode4;
            bytesPerSample = 4;
            break;
        case 5: _getSample = &TraceBigEndian::getSampleCode5;
            bytesPerSample = 4;
            break;
        case 0: _getSample = &TraceBigEndian::getSampleCode6;
            bytesPerSample = 0;
            break;
        case 8: _getSample = &TraceBigEndian::getSampleCode8;
            bytesPerSample = 1;
            break;
        default: _getSample=&TraceBigEndian::getSampleCode1;
    }
}

TraceBigEndian::~TraceBigEndian(){

}
