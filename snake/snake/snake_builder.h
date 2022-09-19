#ifndef SNAKE_BUILDER_H
#define SNAKE_BUILDER_H


#include <QPushButton>
//#include "widget.h"
#include "snake.h"
#include "snake_layout.h"


class SnakeBuilder
{
public:
    SnakeBuilder(SnakeLayout* s): snake_layout_p(s), available_snake(s->get_layout())
    {

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

    bool add_snake_sucessful(Snake *s)
    {
        bool is_snake_not_found_in_buffer = !is_snake_exsist(s);

        if(is_snake_not_found_in_buffer)
        {
            available_snake.push_front(s);
        }

        return is_snake_not_found_in_buffer;
    }

    bool remove_first_snake_sucessful()
    {
        if(available_snake.size() > 1) //ensure that there is at least one snake element in the snake
        {
            available_snake.remove(*(available_snake.cbegin()));
            return true;
        }

        return false;
    }


    SnakeLayout* get_snake_layout_pointer()
    {
        return snake_layout_p;
    }

    std::list<Snake*>& get_available_snake()
    {
        return available_snake;
    }


    void set_available_snake(std::list<Snake*>& snake_list)
    {
        available_snake = snake_list;
    }

private:
    SnakeLayout* snake_layout_p;
    std::list<Snake*>& available_snake;

};














#endif // SNAKE_BUILDER_H
