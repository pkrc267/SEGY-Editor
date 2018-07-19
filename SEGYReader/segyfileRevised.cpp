#include "segyfileRevised.h"
#include <exception>
#include <iostream>
#include <list>
#include <cstdio>
#include <sstream>
#include <exceptions.h>
//#include "traceRevised.h"
using namespace std;


bool SegyFile::isEndTextStanza(const char *c){
    int state = -2;
    while(c){
        switch(state){
            case -2:
                if(*c == '(') state = -1;
                else return false;
                break;
            case -1:
                if(*c == '(') state = 0;
                else return false;
                break;
            case 0:
                if(*c == 'S' || *c == 's') state = 1;
                else if (*c == ' ') state = 0;
                else return false;
                break;
            case 1:
                if(*c == 'E' || *c == 'e') state = 2;
                else return false;
                break;
            case 2:
                if(*c == 'G' || *c == 'g') state = 3;
                else return false;
                break;
            case 3:
                if(*c == ':') state = 4;
                else if(*c == ' ') state = 3;
                else return false;
                break;
            case 4:
                if(*c == 'E' || *c == 'e') state = 5;
                else if(*c == ' ') state = 4;
                else return false;
                break;
            case 5:
                if(*c == 'n' || *c == 'N') state = 6;
                else return false;
                break;
            case 6:
                if(*c == 'd' || *c == 'D') state = 7;
                else return false;
                break;
            case 7:
                if(*c == 'T' || *c == 't') state = 8;
                else if(*c == ' ') state = 7;
                else return false;
                break;
            case 8:
                if(*c == 'e' || *c == 'E') state = 9;
                else return false;
                break;
            case 9:
                if(*c == 'x' || *c == 'X') state = 10;
                else return false;
                break;
            case 10:
                if(*c == 't' || *c == 'T') state = 11;
                else return false;
                break;
            case 11:
                if(*c == ')')state = 12;
                else if(*c == ' ') state = 11;
                else return false;
                break;
            case 12:
                if(*c == ')') return true;
                else return false;
                break;
        }
        c++;
    }
    return false;
}

int SegyFile::fileIndex = 0;
SegyFile::HeaderInfo SegyFile::headerArrayInfo[] = {
    {   3201, 4, "Job Identification Number", true , false},
    {   3205, 4, "Line Number", true , false},
    {   3209, 4, "Reel Number", true , false},
    {   3213, 2, "traces per Ensemble", true, false },
    {   3215, 2, "auxiliary traces per ensemble", true, false },
    {   3217, 2, "Sample Interval (us)", true, true },
    {   3219, 2, "Original Sample interval", true , false},
    {   3221, 2, "Number of samples per data trace", false , true},
    {   3223, 2, "Original Number of samples per data trace", true, false },
    {   3225, 2, "Data sample format code", false, true},
    {   3227, 2, "Ensemble fold", true, false },
    {   3229, 2, "Trace sorting code", true, false },
    {   3231, 2, "Vertical sum code", true, false },
    {   3233, 2, "Sweep frequency at start (Hz)", true , false},
    {   3235, 2, "Sweep frequency at end (Hz)", true , false},
    {   3237, 2, "Sweep length (ms)", true , false},
    {   3239, 2, "Sweep type code", true , false},
    {   3241, 2, "Trace number of sweep channel", true , false},
    {   3243, 2, "Sweep trace taper length at start", true , false},
    {   3245, 2, "Sweep trace taper length at end", true , false},
    {   3247, 2, "Taper type", true , false},
    {   3249, 2, "Correlated data traces", true , false},
    {   3251, 2, "Binary gain recovered", true , false},
    {   3253, 2, "Amplitude recovery method", true, false },
    {   3255, 2, "Measurement system", true, false },
    {   3257, 2, "Impulse signal polarity", true, false },
    {   3259, 2, "Vibratory polarity code", true , false},
    {   3501, 2, "SEG Y Format Revision Number", false , false},
    {   3503, 2, "Fixed length trace flag", false , false},
    {   3505, 2, "Number of Extended Textual Headers", false , false}

};

int SegyFile::getBinaryHeader(int index){
    int startingByte = headerArrayInfo[index].startOffset;
    int numOfBytes = headerArrayInfo[index].numOfBytes;
    return getBinaryHeader(startingByte, numOfBytes);
}
void SegyFile::setBinaryHeader(int value, int index){
    if(headerArrayInfo[index].editable){
        int startingByte = headerArrayInfo[index].startOffset;
        int numOfBytes = headerArrayInfo[index].numOfBytes;
        setBinaryHeader(value, startingByte, numOfBytes);
    }
}
SegyFile::HeaderInfo* SegyFile::getBinaryHeaderInfo(int index){
    return &(headerArrayInfo[index]);
}

SegyFile::SegyFile(string fileName)
{
    fileIndex++;
    originalFileName = fileName;
    //stringstream ss ("");
    //ss<<"/tmp/SEGY.sgy"<<fileIndex;
    //temporaryFileName = ss.str();
    unsigned char _e2a[] =  {
        0,  1,  2,  3,156,  9,134,127,151,141,142, 11, 12, 13, 14, 15,
       16, 17, 18, 19,157,133,  8,135, 24, 25,146,143, 28, 29, 30, 31,
      128,129,130,131,132, 10, 23, 27,136,137,138,139,140,  5,  6,  7,
      144,145, 22,147,148,149,150,  4,152,153,154,155, 20, 21,158, 26,
       32,160,161,162,163,164,165,166,167,168, 91, 46, 60, 40, 43, 33,
       38,169,170,171,172,173,174,175,176,177, 93, 36, 42, 41, 59, 94,
       45, 47,178,179,180,181,182,183,184,185,124, 44, 37, 95, 62, 63,
      186,187,188,189,190,191,192,193,194, 96, 58, 35, 64, 39, 61, 34,
      195, 97, 98, 99,100,101,102,103,104,105,196,197,198,199,200,201,
      202,106,107,108,109,110,111,112,113,114,203,204,205,206,207,208,
      209,126,115,116,117,118,119,120,121,122,210,211,212,213,214,215,
      216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,
      123, 65, 66, 67, 68, 69, 70, 71, 72, 73,232,233,234,235,236,237,
      125, 74, 75, 76, 77, 78, 79, 80, 81, 82,238,239,240,241,242,243,
       92,159, 83, 84, 85, 86, 87, 88, 89, 90,244,245,246,247,248,249,
       48, 49, 50, 51, 52, 53, 54, 55, 56, 57,250,251,252,253,254,255
    };
    for(int i = 0; i<256; i++)    e2a[i] = _e2a[i];
    for(int i = 0; i < 256; i++)        a2e[e2a[i]]=i;

}


string SegyFile::getOriginalFileName() const
{
    return originalFileName;
}

void SegyFile::read(){
    originalFile->seekg(0,ios_base::beg);
    if(originalFile->peek() == 'C')textEncodedIn = ASCII; else textEncodedIn = EBCDIC;
    sampleIntervalOfDataTraces = getBinaryHeader(3217,2);
    numOfSamplesPerDataTrace = getBinaryHeader(3221, 2);
    switch(getBinaryHeader(3225, 2)){
    case 1:dataEncodedIn = IBMFloating;
        bytesPerSample = 4;
        break;
    case 2:dataEncodedIn = TwosComplement4Byte;
        bytesPerSample = 4;
        break;
    case 3:dataEncodedIn = TwosComplement2Byte;
        bytesPerSample = 2;
        break;
    case 4:dataEncodedIn = FixedPointWithGain;
        bytesPerSample = 4;
        break;
    case 5:dataEncodedIn = IEEEFloating;
        bytesPerSample = 4;
        break;
    case 8:dataEncodedIn = TwosComplement1Byte;
        bytesPerSample = 1;
        break;
    case 6:
    case 7:
    default:
        bytesPerSample = 0;
        dataEncodedIn = Invalid;
    }
    int data = getBinaryHeader(3501,2);
    segyRevision = ((data & 0x0000FF00)>>8) + ((data & 0x000000FF)/256);
    if(segyRevision >=1.0){
        if(getBinaryHeader(3503,2) == 1){
            fixedLengthTraces = true;
        }else{
            fixedLengthTraces = false;
        }
        numOfExtendedHeaders = getBinaryHeader(3505,2);
        if(numOfExtendedHeaders>=0){
            variableExtendedHeaders = false;
            traceBeginsAt = 3600+(numOfExtendedHeaders*3200) + 1;
        }else{
            variableExtendedHeaders = true;
            //temporaryFile->seekg(3201);
            //not yet implemented.
            dataEncodedIn = Invalid;
        }
    }else{
        traceBeginsAt=3601;
        variableExtendedHeaders = false;
        numOfExtendedHeaders =0;
        fixedLengthTraces = false;
    }

    //reading traces now
    readTraces();
}

string* SegyFile::getTextHeaderLine(int line){
    int offset = 80*line + 4;
    unsigned char data[77];
    originalFile->seekg(offset,ios_base::beg);
    originalFile->read((char*)data,76);
    data[76] = '\0';
    if(textEncodedIn == EBCDIC){
        for(int i = 0; i<76; i++){
            data[i] = e2a[data[i]];
        }
    }
    return new string((char*) data);
}

void SegyFile::setTextHeaderLine(string _data, int line){
    unsigned char *d = (unsigned char*) _data.data();
    unsigned char data[77];
    unsigned int i = 0;
    for(; i<_data.size() && i<76; i++){
        data[i] = *(d+i);
    }
    for(;i<76;i++){
        data[i] = ' ';
    }
    data[76] = '\0';
    if(textEncodedIn == EBCDIC){
        for(int i = 0; i < 76; i ++){
            data[i] = a2e[data[i]];
        }
    }
    int offset = 80*line + 4;
    originalFile->seekp(offset,ios_base::beg);
    originalFile->write((char*) data, 76);

}

SegyFile::~SegyFile(){
    originalFile->close();
    //std::remove(temporaryFileName.data());
    delete trace;
    delete[] traceOffsets;
}

//                          GETTERS
SegyFile::TextEncoding SegyFile::getTextEncodedIn() const
{
    return textEncodedIn;
}


float SegyFile::getSegyRevision() const
{
    return segyRevision;
}


int SegyFile::getNumOfExtendedHeaders() const
{
    return numOfExtendedHeaders;
}


int SegyFile::getNumOfTraces() const
{
    return numOfTraces;
}


SegyFile::DataEncoding SegyFile::getDataEncodedIn() const
{
    return dataEncodedIn;
}

int SegyFile::getNumOfSamplesPerDataTrace() const
{
    return numOfSamplesPerDataTrace;
}

int SegyFile::getSampleIntervalOfDataTraces() const
{
    return sampleIntervalOfDataTraces;
}


void SegyFile::save(string file){
    if(originalFileName != file){
        originalFile->seekg(0,ios_base::beg);
        fstream *out = new fstream (file.data(), ios_base::out | ios_base::binary | ios_base::trunc );
        if(out->is_open()){
            (*out) << originalFile->rdbuf();
            originalFile->close();
            delete originalFile;
            originalFile = out;
            originalFileName = file;
        }else{
            throw new BadFileException();
        }
    }
}
