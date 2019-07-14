#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QKeyEvent"
#include "control.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->commander = new Commander();



}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{

    switch (event->key()) {


    case Qt::Key_L: commander->command(light_on);break;
    case Qt::Key_Period:  commander->command(light_off);break;

    case Qt::Key_1:  commander->command(grip_open); break;
    case Qt::Key_Q:  commander->command(grip_close); break;

    case Qt::Key_2:  commander->command(wrist_up); break;
    case Qt::Key_W:  commander->command(wrist_down); break;
    case Qt::Key_3:  commander->command(elbow_up); break;
    case Qt::Key_E:  commander->command(elbow_down); break;

    case Qt::Key_4:  commander->command(shoulder_up); break;
    case Qt::Key_R:  commander->command(shoulder_down); break;

    case Qt::Key_5:  commander->command(rotate); break;
    case Qt::Key_T:  commander->command(rotate_anti); break;

    case Qt::Key_P:
        commander->command(all_stop); break;

    case Qt::Key_F:
        commander->flash(3);
    default:
        break;

    }



}

void MainWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {


    case Qt::Key_1:
    case Qt::Key_Q:
        commander->command(grip_stop);
        break;


    case Qt::Key_2:
    case Qt::Key_W:
        commander->command(wrist_stop);
        break;


    case Qt::Key_3:
    case Qt::Key_E:
        commander->command(elbow_stop);
        break;


    case Qt::Key_4:
    case Qt::Key_R:
        commander->command(shoulder_stop);
        break;


    case Qt::Key_5:
    case Qt::Key_T:
        commander->command(rotate_stop);
        break;



    default:
        break;
    }

    updateDeviceList();
}



void MainWidget::updateDeviceList()
{
    if(commander->isDeviceExist())
        this->ui->label->setText("设备已连接。");
    else{
        this->ui->label->setText("未连接设备。");
    }
}



void MainWidget::on_pushButton_clicked()
{
    updateDeviceList();
}
