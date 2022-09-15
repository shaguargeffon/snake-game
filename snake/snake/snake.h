#ifndef SNAKE_H
#define SNAKE_H


#include <QPushButton>


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
    Snake(unsigned int x, unsigned int y): x(index_x), y(index_y)
    {
        dir = None;
    }


    void move_up()
    {
        if(index_y>0)
        {
            index_y--;
        }
    }

    void move_down()
    {
        index_y--;
    }

    void move_left()
    {
        index_x--;
    }


    void move_right()
    {
        index_x++;
    }


private:
    unsigned int index_x;
    unsigned int index_y;
    MoveDirection dir;
};













#endif // SNAKE_H
