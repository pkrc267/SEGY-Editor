#ifndef SEGYFILEREVISED_H
#include <string>
#include <fstream>
#include "traceRevised.h"
#define SEGYFILEREVISED_H

//SX= Self Explanatory
using namespace std;
class SegyFile
{

protected:
    int bytesPerSample;
    virtual void readTraces() = 0;

    bool isEndTextStanza(const char *c);
    /* provide a simple way to convert EBCDIC to ASCII
     * and vice versa.
     */
    unsigned char e2a[256];
    unsigned char a2e[256];

    //file functionalities
    /* Stores the name of the original file
     * So that later when changes must be saved back to it,
     * it can be reopened and edited.
     */
    string originalFileName;
    //string temporaryFileName;// self-explanatory (SX)
    fstream *originalFile;// SX
    /* Traces are read one at a time.
     * This pointer is where every instance of it is initialized
     * and deleted.
     */
    Trace *trace;

    /* Seg-Y file may have unrecognised data sample format.
     * It simply tells whether data sample format is valid or not */
    bool dataValid; //in case the Data format is not legal, it is set to false.

    //recogninising the SEGY Revision Number
    float segyRevision;

    //SEGY 1.0 headers
    bool fixedLengthTraces;
    bool variableExtendedHeaders;
    int numOfExtendedHeaders;

    //recognise the start of traces
    int traceBeginsAt;//stores where the first trace begins
    int numOfTraces;//SX
    int *traceOffsets;//stores the offsets in file for each trace

    //global trace properties if valid, if FixedLengthTraces=True
    int numOfSamplesPerDataTrace;
    int sampleIntervalOfDataTraces;


    //functions for reading onto the SegyFile object
    void read();



public:
    //to manage temporary files.
    //as many segyfiles may be opened simultaneously
    //there must be a way to disambuguate them.
    static int fileIndex;
    //Stores information about BinaryHeaders
    struct HeaderInfo{
        int startOffset;
        int numOfBytes;
        string name;
        bool editable;
        bool mustMatch;
    };
    static HeaderInfo headerArrayInfo[];
    //SEGY Functionality
    enum TextEncoding { ASCII, EBCDIC } textEncodedIn;
    //in case Extended Headers are encoded differently,
    //they will be encoded to the same encoding later
    //textual header is always 3200 byte and at the beginning.
    //therefore no need for a buffer anymore.
    //getter function will on the fly convert the EBCDIC to ASCII for reading purposes



    //the data sample format
    enum DataEncoding { Invalid = 0,
                        IBMFloating = 1,
                        TwosComplement4Byte = 2,
                        TwosComplement2Byte = 3,
                        FixedPointWithGain = 4,
                        IEEEFloating = 5,
                        TwosComplement1Byte = 8 } dataEncodedIn;
    virtual ~SegyFile();
    /* creates fstream on its own.
     * Manages temporary files on its own
     */
    SegyFile(string fileName);
    void save(string file);// save the modified temporay file back onto the original file.
    //SX
    string* getTextHeaderLine(int line);
    //SX
    void setTextHeaderLine(string data, int line);
    //Functionality FOR and FROM BINARY HEADERS
    //FOR binary headers are always at 3200 and 400 bytes long.
    //Functionality is achieved through the file.
    //hence only getter and setters exist for specific headers, which use these
    virtual int getBinaryHeader(int startingByte, int numOfBytes , bool offsetted = false)=0;
    virtual void setBinaryHeader(int value, int startingByte, int numOfBytes, bool offsetted = false)=0;
    //SX
    TextEncoding getTextEncodedIn() const;
    //SX
    float getSegyRevision() const;
    //SX
    int getNumOfExtendedHeaders() const;
    //SX
    int getNumOfTraces() const;
    //SX
    DataEncoding getDataEncodedIn() const;

    //SX
    int getNumOfSamplesPerDataTrace() const;
    //SX
    int getSampleIntervalOfDataTraces() const;
    //SX
    virtual Trace* getTraceAt(int index)=0;
    void setTraceAt(Trace *t, int index);

    /* all binary headers are indexed sorted according to their starting addresses
     */
    int getBinaryHeader(int index);
    void setBinaryHeader(int value,int index);
    //SX
    static SegyFile::HeaderInfo*  getBinaryHeaderInfo(int index);
    string getOriginalFileName() const;

    virtual void convertToBigEndian(string newFileName) = 0;
};

#endif // SEGYFILEREVISED_H
