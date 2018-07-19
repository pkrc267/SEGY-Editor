#ifndef TRACEREVISED_H
#include <fstream>
#define TRACEREVISED_H



using namespace std;
class Trace
{
protected:
    int numOfSamples;
    int sampleInterval;
    int startsAt;
    int index;
    int bytesPerSample;
    fstream *file;
    //double (Trace::*getSample)(const char* );


    virtual double getSampleCode1(const char*)=0;
    virtual double getSampleCode2(const char*)=0;
    virtual double getSampleCode3(const char*)=0;
    virtual double getSampleCode4(const char*)=0;
    virtual double getSampleCode5(const char*)=0;
    virtual double getSampleCode6(const char*)=0;
    virtual double getSampleCode7(const char*)=0;
    virtual double getSampleCode8(const char*)=0;
    virtual double getSample(const char*) = 0;
    virtual void setDE(int de)=0;
public:
    Trace();
    struct HeaderInfo{
        int startOffset;
        int numOfBytes;
        string name;
        bool editable;
    };
    static HeaderInfo headerInfoArray[];
    int getBytesPerSample();
    double getNextSample();//iterates linealy.
    void resetIndex();
    int getNumOfSamples();
    int getSize();
    int getBinaryHeader(int index);
    void setBinaryHeader(int value,int index);
    static Trace::HeaderInfo*  getBinaryHeaderInfo(int index);

    virtual ~Trace();
    virtual void setNextSampleRaw(char*)=0;
    virtual char* getNextSampleRaw(bool asBE)=0;
    virtual int getBinaryHeader(int startingByte, int numOfBytes) = 0;
    virtual void setBinaryHeader(int value, int startingByte, int numOfBytes) = 0;
};

#endif // TRACEREVISED_H
