#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QtGui>
#include <iostream>
#include <QTimerEvent>
#include "config.h"
#include "event_handler.h"
#include <algorithm>
#include <list>
#include "frame.h"



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


        unsigned int x{start_point_coordinate_x};
        unsigned int y{start_point_coordinate_y};

        x+=(element_size_x)*(first_snake_x);
        y+=(element_size_y)*(first_snake_y);

        std::shared_ptr<Snake> p(new Snake(x, y));

        snake_list.push_front(p);

    }


    void init_frame_to_game()
    {
        unsigned int i{0};
        unsigned int j{0};

        //Generate above frame
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }

        //Generate bottom frame
        j = frame_amount_y - 1;
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }


        //Generate left frame
        i = 0;

        for(j = 0; j<frame_amount_y-1; j++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }


        //Generate right frame
        i = frame_amount_x - 1;

        for(j = 0; j<frame_amount_y-1; j++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }

        // Assign frame to the game
        for(auto it = frame_layout_buffer.begin(); it != frame_layout_buffer.end(); it++)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            x+=(element_size_x)*((*it)->get_x());
            y+=(element_size_y)*((*it)->get_y());

            std::shared_ptr<Frame> frame_p(new Frame(x, y));

            frame_p->setParent(this);

            frame_p->move(x, y);

            frame_p->resize(element_size_x, element_size_y);

            frame_p->setStyleSheet("background-color: black");

            frame_buffer.push_back(frame_p);

            frame_p->show();
        }
    }

    void init_snake_to_game()
    {

        for(auto it=snake_list.begin(); it!=snake_list.end(); it++)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            x+=(element_size_x)*(first_snake_x);
            y+=(element_size_y)*(first_snake_y);

            (*it)->setParent(this);
            (*it)->move(x, y);
            (*it)->resize(element_size_x, element_size_y);
            (*it)->setStyleSheet("background-color: red");
            (*it)->show();
        }
    }


    void move_up_callback()
    {
       (*(snake_list.begin()))->set_dir(MoveDirection::UP);
    }


    void move_down_callback()
    {
       (*(snake_list.begin()))->set_dir(MoveDirection::DOWN);
    }


    void move_left_callback()
    {
       (*(snake_list.begin()))->set_dir(MoveDirection::LEFT);
    }


    void move_right_callback()
    {
       (*(snake_list.begin()))->set_dir(MoveDirection::RIGHT);

    }


    void move_to_next_postion()
    {

        auto snake_head = snake_list.begin();

        auto it = snake_list.end();

        std::advance(it, -1);

        *(*it) = *(*snake_head);

        if((*it)->get_dir() == MoveDirection::UP)
        {
            (*it)->move_up();
        }

        if((*it)->get_dir() == MoveDirection::DOWN)
        {
            (*it)->move_down();
        }

        if((*it)->get_dir() == MoveDirection::LEFT)
        {
            (*it)->move_left();
        }

        if((*it)->get_dir() == MoveDirection::RIGHT)
        {
            (*it)->move_right();
        }

        snake_list.push_front(*it);

        snake_list.pop_back();

        for(auto snake_ele : snake_list)
        {
            snake_ele->move(snake_ele->get_x(), snake_ele->get_y());
            snake_ele->show();
        }
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
        }

        if(event->key() == Qt::Key_S)
        {
            move_down_callback();
        }

        if(event->key() == Qt::Key_A)
        {
            move_left_callback();
        }

        if(event->key() == Qt::Key_D)
        {
            move_right_callback();
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
            move_to_next_postion();
            //std::cout<<"Update"<<std::endl;
            timer_counter = timer_recorder;
        }
    }


private:
    int timerId;
    unsigned int game_level;
    unsigned int timer_counter{0};
    unsigned int timer_recorder{0};
    std::list<std::shared_ptr<Snake>> snake_list;
    std::vector<std::shared_ptr<Frame>> frame_layout_buffer;
    std::vector<std::shared_ptr<Frame>> frame_buffer;
};





#endif // WIDGET_H
