#if !defined MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include "Arduino.h"
#include "MessageGenerator.h"


class MessageGenerator
{

    private:
        char localID;
        char destID;
        char header[2];

    public:

        MessageGenerator(char senderID, char recID);

        ~MessageGenerator();

        // Send Confirmation
        // Pre: none
        // Post: char array with the encoded string
        const char* MessageGenerator::confirm();

        // generic IMU Data Broadcast
        // Pre: Integer
        // Post: char array with the encoded string
        const char* MessageGenerator::IMUBroadcast(const char* data);

        // Send Neighbors eachother's IMU values, as well as your own
        // Pre: integer
        // Post: char array with the encoded string
        const char* MessageGenerator::IMURedirect(const char* localData, const char* neighborData);

        // Send request for neighbor's missing data while sending your own
        // Pre: integer
        // Post: char array with the encoded string
        const char* MessageGenerator::requestRedirect(const char* data);

        // Receive all messages from buffers.
        // Pre: const char*
        // Post: char array with the recieved messages for processing
        const char* MessageGenerator::receiveMessages(const char* buffer);

        // Declare priority status to take control of actuator
        // Pre: an unsigned Long containing the time just before sending
        // Post: char array with the encoded string
        const char* MessageGenerator::declarePriority(unsigned long timeStamp);

        // Order the halting of priority swap
        // Pre: none
        // Post: char array with encoded string
        const char* MessageGenerator::standDown();

        // For use by priority Node only.  Request for correction and accuracy data
        // Pre: none
        // Post: char array with encoded string
        const char* MessageGenerator::requestCorrections();





}
