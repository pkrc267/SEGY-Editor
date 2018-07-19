#ifndef SEGYFILELITTLEENDIAN_H
#include <segyfileRevised.h>
#define SEGYFILELITTLEENDIAN_H

class SegyFileLittleEndian : public SegyFile
{
protected:
    void readTraces();
public:
    SegyFileLittleEndian(string fileName);
    int getBinaryHeader(int startingByte, int numOfBytes, bool offsetted=false);
    void setBinaryHeader(int value, int startingByte, int numOfBytes, bool offsetted=false);
    Trace* getTraceAt(int index);
    ~SegyFileLittleEndian();
    void convertToBigEndian(string newFileName);
    //int getBinaryHeader(int index);
    //void setBinaryHeader(int value ,int index);
};

#endif // SEGYFILELITTLEENDIAN_H
