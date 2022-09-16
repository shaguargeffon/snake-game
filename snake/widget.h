#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QTimerEvent>
#include "event_handler.h"


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
    KeyPress(QWidget *parent = 0, unsigned int lvl = 1) : QWidget(parent), game_level(lvl)
    {
        timerId = startTimer(20);

        switch(game_level)
        {
            case 1:
                timer_counter = 5;
                break;

            case 2:
                timer_counter = 10;
                break;

            case 3:
                timer_counter = 20;
                break;

            default:
                timer_counter = 20;
                break;
        }

        timer_recorder = timer_counter;
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

        if(timer_counter>0)
        {
            timer_counter--;
        }
        else
        {
            MoveEvent event(5);
            send_event(&event);
            std::cout<<"Update"<<std::endl;
            timer_counter = timer_recorder;
        }
    }


    void send_event(Event *e)
    {
        e->handle_event();
    }


    ~KeyPress()
    {
        killTimer(timerId);
    }

private:
    int timerId;
    unsigned int game_level;
    unsigned int timer_counter{0};
    unsigned int timer_recorder{0};
};





#endif // WIDGET_H
