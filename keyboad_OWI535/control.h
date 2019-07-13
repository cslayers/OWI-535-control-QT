#ifndef CONTROL_H
#define CONTROL_H
#include <string>

    void command(std::string cmd);


    #define all_stop "00 00 00"



    #define light_on  "00 00 01"
    #define light_off "00 00 00"


    #define grip_open   "01 00 00"
    #define grip_close "02 00 00"

    #define wrist_up   "04 00 00"
    #define wrist_down "08 00 00"

    #define elbow_up   "10 00 00"
    #define elbow_down "20 00 00"

    #define shoulder_up   "40 00 00"
    #define shoulder_down "80 00 00"

    #define rotate "00 01 00"
    #define rotate_anti "00 02 00"


#endif // CONTROL_H
