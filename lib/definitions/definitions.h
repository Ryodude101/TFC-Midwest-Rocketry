#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_



float Error; //shoud probably be defined somewhere else










//will be more useful when programming specific directions to point to
enum cardinal_direction {
    north = 0,
    south = 180,
    east = 90,
    west = -90
}; //TODO::change numbers for control algorithm
cardinal_direction current_course;


#define MAX_NUM_COMMANDS 20 //max number of commands
int current_command = 0; //array index number, incremented in control algorithm when the commans objectives have been reached

struct command {
    cardinal_direction desired_course;
    //float hold_time;       //not needed yet
    //bool roll_direction;   //not needed yet
    bool is_done; //marked off if the command has been executed
}commands[MAX_NUM_COMMANDS]; //use array called commands to access current command from list of them


#endif
