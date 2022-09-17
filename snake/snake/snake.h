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
    Snake(unsigned int pos_x, unsigned int pos_y);

    unsigned int get_x()
    {
        return x;
    }

    unsigned int get_y()
    {
        return y;
    }

    bool operator==(const Snake &s) const
    {
        return ((this->x==s.x) && (this->y==s.y));
    }



private:
    unsigned int x;
    unsigned int y;
};



#endif // SNAKE_H
