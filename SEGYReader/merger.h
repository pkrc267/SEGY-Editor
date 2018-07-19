#ifndef MERGER_H
#define MERGER_H

#include <QString>
#include <string>
#include <fstream>
#include <vector>
#include <segyfileRevised.h>
#include <segyfilebigendian.h>
#include <segyfilelittleendian.h>
#include <traceRevised.h>
#include <tracebigendian.h>
#include <tracelittleendian.h>
#include <QObject>


using namespace std;


struct TimeStruct{
    int year;
    int day;
    int hour;
    int min;
    int sec;
    bool operator <( TimeStruct t2){
        TimeStruct *t1 = this;
        if(t1->year < t2.year){
            return true;
        }else if(t1->day < t2.day){
            return true;
        }else if(t1->hour < t2.hour){
            return true;
        }else if(t1->min < t2.min){
            return true;
        }else if(t1->sec < t2.sec){
            return true;
        }
        return false;
    }
    bool operator >( TimeStruct t2){
        TimeStruct *t1 = this;
        if(t1->year > t2.year){
            return true;
        }else if(t1->day > t2.day){
            return true;
        }else if(t1->hour > t2.hour){
            return true;
        }else if(t1->min > t2.min){
            return true;
        }else if(t1->sec > t2.sec){
            return true;
        }
        return false;
    }
};

struct TraceData{
    Trace* t;
    int seqSegyFile;
    int seqLine;
    TimeStruct time;
};

struct FileData{
    QString name;
    QString location;
    bool BE;
    SegyFile *sf;
    int lineNumber;
    int reelNumber;
    TimeStruct leastTime;
    TraceData *traces;
};




class Merger : public QObject
{
    Q_OBJECT

public:
    enum TraceSortType{
        None,
        Time,
        LineNumberSeq,
        SegyFileSeq
    };
private:
    bool success;
    Merger::TraceSortType traceSortType;
    unsigned char binaryHeader[400];
    unsigned char textualHeader[3200];
    fstream *saveFile;
    QString saveFileName;
    bool timeFormatAgreed;
    vector<FileData*> files;
    float progress;
    float progressStep;
//support
    //static bool  compareTraceByTime(TraceData *t1, TraceData *t2);
    //static bool  compareTraceByLine(TraceData *t1, TraceData *t2);
    static bool  compareTraceDataByTime(TraceData t1, TraceData t2){
        return (t1.time < t2.time);
    }

    static bool  compareTraceDataByLine(TraceData t1, TraceData t2){
        return (t1.seqLine < t2.seqLine);
    }

    static bool  compareTraceDataBySegySeq(TraceData t1, TraceData t2){
        return true;
    }

    static bool  compareFileDataByTime(FileData *f1, FileData *f2){
        return (f1->leastTime < f2->leastTime);
    }

    static bool  compareFileDataByLine(FileData *f1, FileData *f2){
        return (f1->lineNumber < f2->lineNumber);
    }

    static bool  compareFileDataBySegySeq(FileData *f1, FileData *f2){
        return true;
    }

    bool (*compareTrace)(TraceData, TraceData);
    bool (*compareFile)(FileData *f1, FileData *f2);

//    void sortTracesByTime();
//    void sortTracesByLine();
//    void sortTracesBySegySeq();

//    void writeTracesByTime();
//    void writeTracesByLine();
//    void writeTracesBySegySeq();

    bool checkAnyTrue(bool *arr, int size);

public:


    explicit Merger(QObject *parent = 0);

//for selectFilesActivity/Form
    QString getSaveFileName() const;
    void setSaveFileName(const QString &value);

    void addFile(QString loc, bool isBE);
    FileData* getFile(int index);
    void removeFile(int index);
    void setFileBE(int index, bool BE);
    //void removeFile(string location);

    void initializeFiles();

//for ComparepropertiesActivity/Form
    void setBinaryHeader(int value, int index);

//for TextualHeaderActivity/Form
    void setRequiredHeader();
    void setTextualHeaderLine(int lineIndex, QString line);

//for TraceSortActivity/Form
    TraceSortType getTraceSortType() const;
    void setTraceSortType(const TraceSortType &value);

//for PageResult
    void createFile();
    void writeTextualHeader();
    void writeBinaryHeader();
    void readTraces();
    void sortTraces();
    void writeTraces();
    void finish();
    void lastPageRequest();

//support
    int getNumOfFiles();
    bool getSuccess() const;
    void setSuccess(bool value);
    QString getFileNameAt(int index);

signals:
    void independentLegProgress(int progress);
    void lastPage();

public slots:

};

#endif // MERGER_H
