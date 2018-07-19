#ifndef TRACELITTLEENDIAN_H
#define TRACELITTLEENDIAN_H
#include <traceRevised.h>

class TraceLittleEndian : public Trace
{
protected:
    double (TraceLittleEndian::*_getSample)(const char *);
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
    ~TraceLittleEndian();
    TraceLittleEndian(fstream *_file, int de, int seek, int _numOfSamples, int _sampleInterval);
    void setNextSampleRaw(char*);
    char* getNextSampleRaw(bool asBE);
    int getBinaryHeader(int startingByte, int numOfBytes);
    void setBinaryHeader(int value, int startingByte, int numOfBytes);
};

#endif // TRACELITTLEENDIAN_H
