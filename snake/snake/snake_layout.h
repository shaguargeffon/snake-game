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
        unsigned int x{start_point_coordinate_x};
        unsigned int y{start_point_coordinate_y};

        x+=(element_size_x)*(first_snake_x);
        y+=(element_size_y)*(first_snake_y);
        Snake* p = new Snake(x, y);

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
