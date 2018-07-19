#include "traceRevised.h"
#include <cmath>
#include <iostream>

Trace::HeaderInfo Trace::headerInfoArray[] = {
    {1, 4, "Trace sequence number within line", false},
    {5, 4, "Trace sequence number within SEG Y file", false},
    {9, 4, "Original field record number", true},
    {13, 4, "Trace number within the original field record", true},
    {17, 4, "Energy source point number", true},
    {21, 4, "Ensemble number", true},
    {25, 4, "Trace number within the ensemble", true},
    {29, 2, "Trace identification code", true},
    {31, 2, "Number of vertically summed traces yielding this trace", true},
    {33, 2, "Number of horizontally stacked traces yielding this trace", true},
    {35, 2, "Data use", true},
    {37, 4, "Distance from center of the source point to the center of the receiver group", true},
    {41, 4, "Receiver group elevation", true},
    {45, 4, "Surface elevation at source", true},
    {49, 4, "Source depth below surface", true},
    {53, 4, "Datum elevation at receiver group", true},
    {57, 4, "Datum elevation at source", true},
    {61, 4, "Water depth at source", true},
    {65, 4, "Water depth at group", true},
    {69, 2, "Scalar to be applied to all elevations and depths specified", true},
    {71, 2, "Scalar to be applied to all coordinates specified", true},
    {73, 4, "Source coordinate - X", true},
    {77, 4, "Source coordinate - Y", true},
    {81, 4, "Group coordinate - X", true},
    {85, 4, "Group coordinate - Y", true},
    {89, 2, "Coordinate units", true},
    {91, 2, "Weathering velocity", true},
    {93, 2, "Subweathering velocity", true},
    {95, 2, "Uphole time at source in milliseconds", true},
    {97, 2, "Uphole time at group in milliseconds", true},
    {99, 2, "Source static correction in milliseconds", true},
    {101, 2, "Group static correction in milliseconds", true},
    {103, 2, "Total static applied in milliseconds", true},
    {105, 2, "Lag time A", true},
    {107, 2, "Lag Time B", true},
    {109, 2, "Delay recording time", true},
    {111, 2, "Mute time — Start time in milliseconds", true},
    {113, 2, "Mute time — End time in milliseconds", true},
    {115, 2, "Number of samples in this trace", true},
    {117, 2, "Sample interval in microseconds (μs) for this trace", true},
    {119, 2, "Gain type of field instruments", true},
    {121, 2, "Instrument gain constant (dB)", true},
    {123, 2, "Instrument early or initial gain (dB)", true},
    {125, 2, "Correlated", true},
    {127, 2, "Sweep frequency at start (Hz)", true},
    {129, 2, "Sweep frequency at end (Hz)", true},
    {131, 2, "Sweep length in milliseconds", true},
    {133, 2, "Sweep type", true},
    {135, 2, "Sweep trace taper length at start in milliseconds", true},
    {137, 2, "Sweep trace taper length at end in milliseconds", true},
    {139, 2, "Taper type", true},
    {141, 2, "Alias filter frequency (Hz), if used", true},
    {143, 2, "Alias filter slope (dB/octave)", true},
    {145, 2, "Notch filter frequency (Hz), if used", true},
    {147, 2, "Notch filter slope (dB/octave)", true},
    {149, 2, "Low-cut frequency (Hz), if used", true},
    {151, 2, "High-cut frequency (Hz), if used", true},
    {153, 2, "Low-cut slope (dB/octave)", true},
    {155, 2, "High-cut slope (dB/octave)", true},
    {157, 2, "Year data recorded", true},
    {159, 2, "Day of year (Julian day for GMT and UTC time basis)", true},
    {161, 2, "Hour of day (24 hour clock)", true},
    {163, 2, "Minute of hour", true},
    {165, 2, "Second of minute", true},
    {167, 2, "Time basis code:\n1 = Local\n2 = GMT (Greenwich Mean Time)\n3 = Other, should be explained in a user defined stanza in the Extended Textual File Header\n4 = UTC (Coordinated Universal Time)", true},
    {169, 2, "Trace weighting factor — Defined as 2^-N volts for the least significant bit", true},
    {171, 2, "Geophone group number of roll switch position one", true},
    {173, 2, "Geophone group number of trace number one within original field record", true},
    {175, 2, "Geophone group number of last trace within original field record", true},
    {177, 2, "Gap size (total number of groups dropped)", true},
    {179, 2, "Over travel associated with taper at beginning or end of line:\n1 = down (or behind)\n2 = up (or ahead)", true},
    {181, 4, "X coordinate of ensemble (CDP) position of this trace", true},
    {185, 4, "Y coordinate of ensemble (CDP) position of this trace", true},
    {189, 4, "For 3-D poststack data, this field should be used for the in-line number", true},
    {193, 4, "For 3-D poststack data, this field should be used for the cross-line number", true},
    {197, 4, "Shotpoint number", true},
    {201, 2, "Scalar to be applied to the shotpoint number", true},
    {203, 2, "Trace value measurement unit:-\n1 = Other (should be described in Data Sample Measurement Units Stanza)\n0 = Unknown\n1 = Pascal (Pa)\n2 = Volts (v)\n3 = Millivolts (mV)\n4 = Amperes (A)\n5 = Meters (m)\n6 = Meters per second (m/s)\n7 = Meters per second squared (m/s 2 )\n8 = Newton (N)9 = Watt (W)", true},
    {205, 4, "Transduction Constant Mantissa", true},
    {209, 2, "Transduction Constant Exponent", true},
    {211, 2, "-1 = Other (should be described in Data Sample Measurement Unit stanza)\n0 = Unknown\n1 = Pascal (Pa)\n2 = Volts (v)\n3 = Millivolts (mV)\n4 = Amperes (A)\n5 = Meters (m)\n6 = Meters per second (m/s)\n7 = Meters per second squared (m/s 2 )\n8 = Newton (N)\n9 = Watt (W)", true},
    {213, 2, "Device/Trace Identifier", true},
    {215, 2, "Scalar to be applied to times specified", true},
    {217, 2, "Source Type/Orientation\n-1 to -n = Other (should be described in Source Type/Orientation stanza)\n0 = Unknown\n1 = Vibratory - Vertical orientation\n2 = Vibratory - Cross-line orientation\n3 = Vibratory - In-line orientation\n4 = Impulsive - Vertical orientation\n5 = Impulsive - Cross-line orientation\n6 = Impulsive - In-line orientation\n7 = Distributed Impulsive - Vertical orientation\n8 = Distributed Impulsive - Cross-line orientation\n9 = Distributed Impulsive - In-line orientation", true},
    {219, 4, "Source Energy Direction with respect to source Orientation(Integer)", true},
    {223, 2, "Source Energy Direction with respect to source Orientation(Tenths)", true},
    {225, 4, "Source Measurement(Mantissa)", true},
    {229, 2, "Source Measurement(Exponent)", true},
    {231, 2, "Source Measurement Unit\n-1 = Other (should be described in Source Measurement Unit stanza)\n0 = Unknown\n1 = Joule (J)\n2 = Kilowatt (kW)\n3 = Pascal (Pa)\n4 = Bar (Bar)\n4 = Bar-meter (Bar-m)\n5 = Newton (N)\n6 = Kilograms (kg)", true},
};

int Trace::getBytesPerSample(){
    return bytesPerSample;
}

double Trace::getNextSample(){
    if(index >= numOfSamples) {index = 0; file->seekg(startsAt + 240); }
    char d[bytesPerSample];
    file->read(d,bytesPerSample);
    index ++;
    return getSample(d);
}

void Trace::resetIndex(){
    index = 0;
    file->seekg(startsAt + 240);
}

int Trace::getNumOfSamples(){
    return numOfSamples;
}

int Trace::getSize(){
    return (240 + (numOfSamples * bytesPerSample));
}

int Trace::getBinaryHeader(int index){
    return getBinaryHeader(headerInfoArray[index].startOffset,headerInfoArray[index].numOfBytes);
}
void Trace::setBinaryHeader(int value, int index){
    if(headerInfoArray[index].editable){
        setBinaryHeader(value,headerInfoArray[index].startOffset, headerInfoArray[index].numOfBytes);
    }
}
Trace::HeaderInfo* Trace::getBinaryHeaderInfo(int index){
    return &(headerInfoArray[index]);
}

Trace::~Trace(){}
Trace::Trace(){}
