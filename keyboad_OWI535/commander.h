#ifndef COMMANDER_H
#define COMMANDER_H

#include "control.h"

#include <string>
using std::string;

class Commander
{
public:
    Commander();


    void flash(int);
    bool isDeviceExist();
    void command(int);
    void call();
private:
    string byte0 = "00";
    string byte1 = "00";
    string byte2 = "00";


    int grip = 0;
    int wrist = 0;
    int elbow = 0;
    int shoulder = 0;

};


#define all_stop 0
#define light_on  1
#define light_off 2
#define grip_open 3
#define grip_close 4
#define wrist_up   5
#define wrist_down 6
#define elbow_up   7
#define elbow_down 8
#define shoulder_up   9
#define shoulder_down 10
#define rotate 11
#define rotate_anti 12
#define grip_stop 13
#define wrist_stop 14
#define elbow_stop 15
#define shoulder_stop 16
#define rotate_stop 17


#endif // COMMANDER_H
