#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QTimerEvent>
#include "config.h"
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


class Game : public QWidget
{
    Q_OBJECT    
public:
    Game(QWidget *parent = 0, unsigned int lvl = 1) : QWidget(parent), game_level(lvl)
    {
        timerId = startTimer(timer_scale);

        switch(game_level)
        {
            case 1:
                timer_counter = timer_multiplier_hard;
                break;

            case 2:
                timer_counter = timer_multiplier_normal;
                break;

            case 3:
                timer_counter = timer_multiplier_easy;
                break;

            default:
                timer_counter = timer_multiplier_easy;
                break;
        }

        timer_recorder = timer_counter;
    }


    ~Game()
    {
        killTimer(timerId);
    }


protected:
    void keyPressEvent(QKeyEvent *event)
    {
        if(event->key() == Qt::Key_W)
        {
            std::cout<<"Set up direction."<<std::endl;
        }

        if(event->key() == Qt::Key_S)
        {
            std::cout<<"Set down direction"<<std::endl;
        }

        if(event->key() == Qt::Key_A)
        {
            std::cout<<"Set left direction."<<std::endl;
        }

        if(event->key() == Qt::Key_D)
        {
            std::cout<<"Set right direction."<<std::endl;
        }

        if(event->key() == Qt::Key_P)
        {
            std::cout<<"Stop game."<<std::endl;
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


private:
    int timerId;
    unsigned int game_level;
    unsigned int timer_counter{0};
    unsigned int timer_recorder{0};

};





#endif // WIDGET_H
