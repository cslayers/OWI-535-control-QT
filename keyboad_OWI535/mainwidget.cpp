#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QKeyEvent"
#include "control.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_L: command(light_on);break;
    case Qt::Key_Period: command(light_off);break;

    case Qt::Key_1: command(grip_open); break;
    case Qt::Key_Q: command(grip_close); break;

    case Qt::Key_2: command(wrist_up); break;
    case Qt::Key_W: command(wrist_down); break;

    case Qt::Key_3: command(elbow_up); break;
    case Qt::Key_E: command(elbow_down); break;

    case Qt::Key_4: command(shoulder_up); break;
    case Qt::Key_R: command(shoulder_down); break;

    case Qt::Key_5: command(rotate); break;
    case Qt::Key_T: command(rotate_anti); break;

    case Qt::Key_P:
        command(all_stop);
    default:
        break;
    }
}

void MainWidget::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {

    case Qt::Key_Greater:

    case Qt::Key_1:
    case Qt::Key_Q:

    case Qt::Key_2:
    case Qt::Key_W:

    case Qt::Key_3:
    case Qt::Key_E:

    case Qt::Key_4:
    case Qt::Key_R:

    case Qt::Key_5:
    case Qt::Key_T:

    case Qt::Key_P:
        command(all_stop);
        break;
    default:
        break;
    }
}
