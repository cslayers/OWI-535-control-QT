#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>

#include "commander.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);

    void updateDeviceList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWidget *ui;

    Commander* commander;
};

#endif // MAINWIDGET_H
