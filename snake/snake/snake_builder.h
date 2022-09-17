#ifndef SNAKE_BUILDER_H
#define SNAKE_BUILDER_H


#include <QPushButton>
#include "widget.h"
#include "snake.h"
#include "snake_layout.h"


class SnakeBuilder
{
public:
    SnakeBuilder(SnakeLayout* s, Game& w)
    {
        s->build_layout();

        for(auto it=s->get_layout().begin(); it!=s->get_layout().end(); it++)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            x+=(element_size_x)*((*it)->get_x());
            y+=(element_size_y)*((*it)->get_y());

            Snake* snake_p = new Snake(x, y);

            snake_p->setParent(&w);

            snake_p->move(x, y);

            snake_p->resize(element_size_x, element_size_y);

            snake_p->setStyleSheet("background-color: red");

            available_snake.push_front(snake_p);

            snake_p->show();
        }
    }


    bool is_snake_exsist(Snake *s)
    {
        bool res = false;

        for(auto snake_p : available_snake)
        {
            if(*snake_p == *s)
            {
                res = true;
                break;
            }
        }

        return res;
    }

    bool is_adding_snake_sucessful(Snake *s)
    {
        bool is_snake_not_found_in_buffer = !is_snake_exsist(s);

        if(is_snake_not_found_in_buffer)
        {
            available_snake.push_front(s);
        }

        return is_snake_not_found_in_buffer;
    }

    bool is_removing_first_snake_sucessful()
    {
        if(available_snake.size() > 1) //ensure that there is at least one snake element in the snake
        {
            available_snake.remove(*(available_snake.cbegin()));
            return true;
        }

        return false;
    }


private:
    std::list<Snake*> available_snake;
};














#endif // SNAKE_BUILDER_H
