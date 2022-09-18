#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QTimerEvent>
#include "config.h"
#include "event_handler.h"
#include "snake_builder.h"



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


    void set_snake_builder(SnakeBuilder* s)
    {
        snake_builder_p = s;
    }


    void initial_snake_to_game()
    {
        auto s = snake_builder_p->get_snake_layout_pointer();
        s->build_layout();

        for(auto it=s->get_layout().begin(); it!=s->get_layout().end(); it++)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            x+=(element_size_x)*((*it)->get_x());
            y+=(element_size_y)*((*it)->get_y());

            Snake* snake_p = new Snake(x, y);

            snake_p->setParent(this);

            snake_p->move(x, y);

            snake_p->resize(element_size_x, element_size_y);

            snake_p->setStyleSheet("background-color: red");

            snake_builder_p->get_available_snake().push_front(snake_p);

            snake_p->show();
        }
    }


    void move_up_callback()
    {
       Snake* snake_p = *((snake_builder_p->get_available_snake()).begin());
       snake_p->move_up();
       snake_p->move(snake_p->get_x(), snake_p->get_y());

       std::cout<<"x: "<<snake_p->get_x()<<std::endl;
       std::cout<<"y: "<<snake_p->get_y()<<std::endl;



       snake_p->show();
    }


    void move_down_callback()
    {
       Snake* snake_p = *((snake_builder_p->get_available_snake()).begin());
       snake_p->move_down();
       snake_p->move(snake_p->get_x(), snake_p->get_y());
       snake_p->show();
    }


    void move_left_callback()
    {
       Snake* snake_p = *((snake_builder_p->get_available_snake()).begin());
       snake_p->move_left();
       snake_p->move(snake_p->get_x(), snake_p->get_y());
       snake_p->show();
    }


    void move_right_callback()
    {
       Snake* snake_p = *((snake_builder_p->get_available_snake()).begin());
       snake_p->move_right();
       snake_p->move(snake_p->get_x(), snake_p->get_y());
       snake_p->show();
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
            move_up_callback();
            std::cout<<"Set up direction."<<std::endl;
        }

        if(event->key() == Qt::Key_S)
        {
            move_down_callback();
            std::cout<<"Set down direction"<<std::endl;
        }

        if(event->key() == Qt::Key_A)
        {
            move_left_callback();
            std::cout<<"Set left direction."<<std::endl;
        }

        if(event->key() == Qt::Key_D)
        {
            move_right_callback();
            std::cout<<"Set right direction."<<std::endl;
        }

        if(event->key() == Qt::Key_P)
        {
            //move_right_callback();
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

            std::cout<<"Update"<<std::endl;
            timer_counter = timer_recorder;
        }
    }





private:
    int timerId;
    unsigned int game_level;
    unsigned int timer_counter{0};
    unsigned int timer_recorder{0};
    SnakeBuilder* snake_builder_p;
};





#endif // WIDGET_H
