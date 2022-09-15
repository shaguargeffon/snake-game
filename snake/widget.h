#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QTimerEvent>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    virtual ~Widget();

private:
    Ui::Widget *ui;

};



class KeyPress : public QWidget
{
    Q_OBJECT
public:
    KeyPress(QWidget *parent = 0) : QWidget(parent)
    {
        timerId = startTimer(2000);
    }

protected:
    void keyPressEvent(QKeyEvent *event)
    {
        if(event->key() == Qt::Key_Escape)
        {
            std::cout<<"press ESC key."<<std::endl;
        }
    }

    void keyReleaseEvent(QKeyEvent *event)
    {
        if(event->key() == Qt::Key_Escape)
        {
            std::cout<<"release ESC key."<<std::endl;
        }
    }

    void timerEvent(QTimerEvent *event)
    {
        if(event == nullptr)
        {
            std::cout<<"Event is null."<<std::endl;
        }

        std::cout<<"Update"<<std::endl;
    }


    ~KeyPress()
    {
        killTimer(timerId);
    }

private:
    int timerId;
};





#endif // WIDGET_H
