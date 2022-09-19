#ifndef SNAKE_H
#define SNAKE_H


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



class Snake: public QPushButton
{
public:
    Snake(unsigned int pos_x, unsigned int pos_y);

    unsigned int get_x()
    {
        return x;
    }

    void set_x(unsigned int pos_x)
    {
        x = pos_x;
    }


    unsigned int get_y()
    {
        return y;
    }

    void set_y(unsigned int pos_y)
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
    unsigned int x;
    unsigned int y;
    MoveDirection dir{MoveDirection::NONE};
};



#endif // SNAKE_H
