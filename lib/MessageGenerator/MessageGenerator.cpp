#include <MessageGenerator.h>
#include <arduino.h>

using namespace std;

MessageGenerator(char senderID, char recID){
    localID = senderID;
    destID = recID;
    strcat (header,destID);
    strcat (header,localID);
}

~MessageGenerator(){}

const char* MessageGenerator::confirm(){
    char message[6];
    strcat(message, header);
    strcat(message, 'YY');

    return message;
}

const char* MessageGenerator::IMUBroadcast(const char* data){
    char message[ask wesley];
    strcat(message, header);
    strcat(message, 'DD');
    strcat(message, '<');
    strcat(message, data);
    strcat(message,'>');

    return message;
}

const char* MessageGenerator::IMURedirect(const char* localData, const char* neighborData){
    char message[2times ask wesley plus sep char];
    strcat(message, header);
    strcat(message, 'DR');
    strcat(message, '<');
    strcat(message, localData);
    strcat(message,'/');
    strcat(message,neighborData);
    strcat(message,'>');

    return message;
}

const char* MessageGenerator::requestCorrections(){
    char message[];
    strcat(message, header);
    strcat(message, 'CC');

    return message;
}

const char* MessageGenerator::requestRedirect(const char* data){
    char message[sumthing];
    strcat(message, header);
    strcat(message, 'RD');
    strcat(message, '<');
    strcat(message, data);
    strcar(message, '>');

    return message;
}

const char* MessageGenerator::declarePriority(unsigned long timeStamp){
    char message[sumthing];
    strcat(message, header);
    strcat(message, 'PP');
    strcat(message, '<');
    strcat(message,timeStamp);
    strcat(message,'>');

    return message;
}

const char* MessageGenerator::standDown(){
    char message[];
    strcat(message, header);
    strcat(message, 'SD');

    return message;
}
