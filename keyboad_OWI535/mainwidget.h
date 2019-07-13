#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QKeyEvent>

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



private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
