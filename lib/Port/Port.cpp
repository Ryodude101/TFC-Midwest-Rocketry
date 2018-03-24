#include <Port.h>
#include <Arduino.h>

using namespace std;

Port::Port(HardwareSerial *serial, int baud){
    _HardSerial = serial;
    _HardSerial.begin(baud);
}

~Port(){
    _HardSerial.end();
}

void Port::send(char* message, int length){
    _HardSerial.write(message, length);
}

void Port::receive(const char* output){
    int counter = 0;

    //It is possible for this loop to block if newline is not detected.
    while (_HardSerial.available() > 0 || output[counter] != '\n'){
        output[counter] = _HardSerial.readByte();
        counter++;
    }

    return output;
}
