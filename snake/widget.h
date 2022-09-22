#pragma once

#include <iostream>
#include <list>
#include <algorithm>
#include <memory>
#include <time.h>
#include <QWidget>
#include <QtGui>
#include <QTimerEvent>
#include <QApplication>
#include "config.h"
#include "frame.h"
#include "snake.h"



extern QApplication* application;

void get_app_pointer(QApplication* app);


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
                timer_counter_movement = timer_multiplier_hard;
                break;

            case 2:
                timer_counter_movement = timer_multiplier_normal;
                break;

            case 3:
                timer_counter_movement = timer_multiplier_easy;
                break;

            default:
                timer_counter_movement = timer_multiplier_easy;
                break;
        }

        timer_recorder_movement = timer_counter_movement;

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

        //Save index of above frame
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }

        //Save index of bottom frame
        j = frame_amount_y - 1;
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }

        //Save index of left frame
        i = 0;

        for(j = 0; j<frame_amount_y-1; j++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout_buffer.push_back(p);
        }

        //Save index of right frame
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



    bool check_game_over()
    {
        auto it = snake_list.begin();

        unsigned int pos_x = (*it)->get_x();
        unsigned int pos_y = (*it)->get_y();

        if((*it)->get_dir() == MoveDirection::UP)
        {
             pos_y -= element_size_y;
        }
        else if((*it)->get_dir() == MoveDirection::DOWN)
        {
            pos_y += element_size_y;
        }

        else if((*it)->get_dir() == MoveDirection::LEFT)
        {
            pos_x -= element_size_x;
        }
        else if((*it)->get_dir() == MoveDirection::RIGHT)
        {
            pos_x += element_size_x;
        }
        else
        {
            return false;
        }

        for(auto iter=frame_buffer.begin(); iter!=frame_buffer.end(); iter++)
        {
            if ((*iter)->get_x() == pos_x && (*iter)->get_y() == pos_y)
            {
                return true;
            }
        }

        for(auto iter=snake_list.begin(); iter!=snake_list.end(); iter++)
        {
            if ((*iter)->get_x() == pos_x && (*iter)->get_y() == pos_y)
            {
                return true;
            }
        }

        return false;
    }


    std::vector<std::shared_ptr<Snake>>::iterator find_overlapped_iterator()
    {
        auto it = snake_list.begin();

        unsigned int pos_x = (*it)->get_x();
        unsigned int pos_y = (*it)->get_y();

        if((*it)->get_dir() == MoveDirection::UP)
        {
             pos_y -= element_size_y;
        }

        if((*it)->get_dir() == MoveDirection::DOWN)
        {
            pos_y += element_size_y;
        }

        if((*it)->get_dir() == MoveDirection::LEFT)
        {
            pos_x -= element_size_x;
        }

        if((*it)->get_dir() == MoveDirection::RIGHT)
        {
            pos_x += element_size_x;
        }


        for(auto iter=block_buffer.begin(); iter!=block_buffer.end(); iter++)
        {
            if ((*iter)->get_x() == pos_x && (*iter)->get_y() == pos_y)
            {
                return iter;
            }
        }

        return block_buffer.end();
    }


    bool move_to_next_postion()
    {
        bool is_game_over = check_game_over();

        if(is_game_over)
        {
            application->exit(0);
        }

        if(stop_control)
        {
            return false;
        }

        auto it = find_overlapped_iterator();

        if(it != block_buffer.end()) //the next snake position has no overlapping with the block buffer
        {
            (*it)->set_dir((*(snake_list.begin()))->get_dir());
            snake_list.push_front(*it);
            block_buffer.erase(it);
        }
        else
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

        return true;
    }


    bool generate_new_block()
    {
        if(stop_control)    //quick fail
        {
            return false;
        }

        srand((unsigned)time(NULL));

        if(snake_list.size() <= game_snake_max_length)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            unsigned int index_x = rand()%(frame_amount_x-2) + 1;
            unsigned int index_y = rand()%(frame_amount_y-2) + 1;

            x+=(element_size_x)*(index_x);
            y+=(element_size_y)*(index_y);

            bool is_block_overlapped_with_snake = false;
            for(auto snake : snake_list)
            {
                if ((snake->get_x() == x) && (snake->get_y() == y))
                {
                    is_block_overlapped_with_snake = true;
                    break;
                }
            }

            bool is_block_overlapped_with_block_buffer = false;
            for(auto snake : block_buffer)
            {
                if ((snake->get_x() == x) && (snake->get_y() == y))
                {
                    is_block_overlapped_with_block_buffer = true;
                    break;
                }
            }


            if(!is_block_overlapped_with_block_buffer && !is_block_overlapped_with_snake) // the block not found, so can be created
            {
                std::shared_ptr<Snake> p(new Snake(x, y));
                p->setParent(this);
                p->move(x, y);
                p->resize(element_size_x, element_size_y);
                p->setStyleSheet("background-color: red");
                block_buffer.push_back(p);
                p->show();

            }
            else
            {
                //block overlapped with snake or already generated, then not generated.
                return false;
            }

            return true;
        }

        return false;
    }



    ~Game()
    {
        killTimer(timerId);
    }


protected:
    void keyPressEvent(QKeyEvent *event)
    {
        if(!stop_control)
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
        }

        if(event->key() == Qt::Key_P)
        {
            if(stop_control)
            {
                stop_control = false;
            }
            else
            {
                stop_control = true;
            }
        }
    }


    void timerEvent(QTimerEvent *event)
    {
        if(event == nullptr)
        {
            std::cout<<"Event is null."<<std::endl;
        }

        if(!stop_control)
        {
            if(timer_counter_movement>0)
            {
                timer_counter_movement--;
            }
            else
            {
                move_to_next_postion();
                timer_counter_movement = timer_recorder_movement;
            }


            if(timer_counter_create_new_block >0)
            {
                timer_counter_create_new_block--;
            }
            else
            {
                generate_new_block();
                timer_counter_create_new_block = timer_creation_new_block;
            }
        }
    }


private:
    int timerId;
    unsigned int game_level;
    unsigned int timer_counter_movement;
    unsigned int timer_recorder_movement;
    unsigned int timer_counter_create_new_block{timer_creation_new_block};
    std::list<std::shared_ptr<Snake>> snake_list;
    std::vector<std::shared_ptr<Snake>> block_buffer;
    std::vector<std::shared_ptr<Frame>> frame_layout_buffer;
    std::vector<std::shared_ptr<Frame>> frame_buffer;
    bool stop_control{false};
};

