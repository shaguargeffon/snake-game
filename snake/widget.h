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


//extern QApplication* application;

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


using SNAKE_TYPE = unsigned int;
using FRAME_TYPE = unsigned int;
using COORDINATE_TYPE = unsigned int;
using TIMER_COUNTER_TYPE = unsigned int;
using GAME_LEVEL_TYPE = unsigned int;
using TIMER_ID_TYPE = int;


class Game : public QWidget
{
    Q_OBJECT    

public:

    Game(QWidget *parent = 0, GAME_LEVEL_TYPE lvl = 1);

    void init_frame_to_game();

    void init_snake_to_game();

    void move_up_callback();
    void move_down_callback();
    void move_left_callback();
    void move_right_callback();

    bool check_game_over();

    std::vector<std::shared_ptr<Snake<SNAKE_TYPE>>>::iterator find_overlapped_iterator();

    bool move_to_next_postion();

    bool generate_new_block();

    ~Game();


protected:
    void keyPressEvent(QKeyEvent *event);

    void timerEvent(QTimerEvent *event);


private:
    TIMER_ID_TYPE timerId;

    GAME_LEVEL_TYPE game_level;

    TIMER_COUNTER_TYPE timer_counter_movement;
    TIMER_COUNTER_TYPE timer_recorder_movement;
    TIMER_COUNTER_TYPE timer_counter_create_new_block{timer_creation_new_block};

    std::list<std::shared_ptr<Snake<SNAKE_TYPE>>> snake_list;
    std::vector<std::shared_ptr<Snake<SNAKE_TYPE>>> block_buffer;

    std::vector<std::shared_ptr<Frame<FRAME_TYPE>>> frame_layout_buffer;
    std::vector<std::shared_ptr<Frame<FRAME_TYPE>>> frame_buffer;

    bool stop_control{false};
};

