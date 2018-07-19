#ifndef TRACEBIGENDIAN_H
#define TRACEBIGENDIAN_H

#include <traceRevised.h>

class TraceBigEndian : public Trace
{
protected:
    double (TraceBigEndian::*_getSample)(const char *d);
    double getSampleCode1(const char*);
    double getSampleCode2(const char*);
    double getSampleCode3(const char*);
    double getSampleCode4(const char*);
    double getSampleCode5(const char*);
    double getSampleCode6(const char*);
    double getSampleCode7(const char*);
    double getSampleCode8(const char*);
    double getSample(const char*);
    void setDE(int de);
public:
    ~TraceBigEndian();
    TraceBigEndian(fstream *_file, int de, int seek, int _numOfSamples, int _sampleInterval);
    void setNextSampleRaw(char*);
    char* getNextSampleRaw(bool asBE);
    int getBinaryHeader(int startingByte, int numOfBytes);
    void setBinaryHeader(int value, int startingByte, int numOfBytes);
};

#endif // TRACEBIGENDIAN_H
