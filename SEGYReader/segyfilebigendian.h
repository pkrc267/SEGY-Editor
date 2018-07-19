#ifndef SEGYFILEBIGENDIAN_H
#define SEGYFILEBIGENDIAN_H

#include <segyfileRevised.h>

class SegyFileBigEndian : public SegyFile
{
protected:
    void readTraces();
public:
    int getBinaryHeader(int startingByte, int numOfBytes , bool offsetted = false);
    void setBinaryHeader(int value, int startingByte, int numOfBytes, bool offsetted = false);
    Trace* getTraceAt(int index);
    SegyFileBigEndian(string fileName);
    ~SegyFileBigEndian();
    void convertToBigEndian(string fileName);
};

#endif // SEGYFILEBIGENDIAN_H
