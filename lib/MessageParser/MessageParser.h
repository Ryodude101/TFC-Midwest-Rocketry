#if !defined MESSAGEPARSER_H
#define MESSAGEPARSER_H

#include "Arduino.h"

using namespace std;

class MessageParser{

    private:
        char buffer[360] = {0};
        DataBank* storage;

    public:
        MessageParser(DataBank* data);
        ~MessageParser();

        void MessageParser::parseAllIncoming();
        void MessageParser::addToBuffer(const char* messages);
}
