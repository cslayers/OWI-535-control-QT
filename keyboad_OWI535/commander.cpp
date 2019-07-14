#include <QString>
#include <QDebug>
#include "commander.h"

#include "control.h"

#include <QThread>



Commander::Commander()
{   
    flash(6);
}


void Commander::flash(int t){

    for(int i=0;i<t;i++){
        command(light_on);
        QThread::msleep(50);
        command(light_off);
        QThread::msleep(20);
    }
}


bool Commander::isDeviceExist()
{
    return deviceExist();
}

void Commander::command(int s)
{
    if(s == light_on) byte2 = "01";
    if(s == light_off) byte2 = "00";

    if(s == rotate) byte1 = "01";
    if(s == rotate_anti) byte1 = "02";
    if(s == rotate_stop) byte1 = "00";

    if(s== all_stop)
        byte0 = byte1 = byte2 = "00";


    if( s == grip_close) grip = 1;
    if( s == grip_open)  grip = 2;
    if( s == grip_stop)  grip = 0;

    if( s == wrist_up)    wrist = 1;
    if( s == wrist_down)  wrist = 2;
    if( s == wrist_stop)  wrist = 0;

    if( s == elbow_up)    elbow = 1;
    if( s == elbow_down)  elbow = 2;
    if( s == elbow_stop)  elbow = 0;


    if( s == shoulder_up)    shoulder = 1;
    if( s == shoulder_down)  shoulder = 2;
    if( s == shoulder_stop)  shoulder = 0;


    int byte0right = grip + 4 * wrist;
    int byte0left  = elbow + 4 * shoulder;

    QString right = QString::number(byte0right, 16);
    QString left =  QString::number(byte0left ,16);

    QString b0 = left + right;

    byte0 = b0.toStdString();

    call();
}

void Commander::call()
{
    string command = byte0 + " " + byte1 + " " + byte2;
    excute(command);
}
