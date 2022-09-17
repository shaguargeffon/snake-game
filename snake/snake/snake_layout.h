#ifndef SNAKE_LAYOUT_H
#define SNAKE_LAYOUT_H

#include "config.h"
#include "snake.h"
#include <algorithm>


class SnakeLayout
{
public:
    SnakeLayout() = default;

    void build_layout()
    {
        Snake* p = new Snake(first_snake_x, first_snake_y);
        snake_layout.push_front(p);
    }

    std::list<Snake*>& get_layout()
    {
        return snake_layout;
    }

    ~SnakeLayout() = default;

private:
    std::list<Snake*> snake_layout;
};



#endif //
