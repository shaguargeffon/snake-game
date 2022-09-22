#pragma once


#include <QPushButton>
#include "config.h"

enum class MoveDirection
{
    NONE = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4
};


template <typename T>
class Snake: public QPushButton
{
public:
    Snake(T pos_x, T pos_y): x(pos_x), y(pos_y)
    {
    }

    T get_x()
    {
        return x;
    }

    void set_x(T pos_x)
    {
        x = pos_x;
    }


    T get_y()
    {
        return y;
    }

    void set_y(T pos_y)
    {
        y = pos_y;
    }


    bool operator==(const Snake &s) const
    {
        return ((this->x==s.x) && (this->y==s.y));
    }

    void move_up()
    {
        y-= element_size_y;
    }

    void move_down()
    {
        y+=element_size_y;
    }


    void move_left()
    {
        x-=element_size_x;
    }

    void move_right()
    {
        x+=element_size_x;
    }


    void set_dir(MoveDirection direction)
    {
        dir = direction;
    }

    MoveDirection get_dir()
    {
        return dir;
    }


    Snake& operator=(const Snake &s)
    {
        this->x = s.x;
        this->y = s.y;
        this->dir = s.dir;

        return *this;
    }


private:
    T x;
    T y;
    MoveDirection dir{MoveDirection::NONE};
};

