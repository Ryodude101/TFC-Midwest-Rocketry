#if !defined PORT_H
define PORT_H

#include "Port.h"
#include "Serial.h"
#include "HardwareSerial.h"

class Port
{
    private:
        int bufferSize = 100;
        charLimit = 50;
        HardwareSerial* _HardSerial;

    public:

        // Pre: You must pass a reference to the serial port you want
        //      to use with this object.
        // Post: You've got a perfectly wrapped sammich... I mean serial port.
        Port(HardwareSerial *Serial, int baud);
        ~Port();

        void Port::send(const char* message, int length);

        void Port::Receive();

}
