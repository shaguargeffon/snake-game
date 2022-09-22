#pragma once

#include <QPushButton>
#include "config.h"

template <typename T>
class Frame: public QPushButton
{
public:
    Frame(T pos_x, T pos_y): x(pos_x), y(pos_y)
    {

    }

    T get_x()
    {
        return x;
    }

    T get_y()
    {
        return y;
    }


private:
    T x;
    T y;
};

