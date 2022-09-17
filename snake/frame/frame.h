#ifndef FRAME_H
#define FRAME_H

#include <QPushButton>
#include "config.h"




class Frame: public QPushButton
{
public:
    Frame(unsigned int pos_x, unsigned int pos_y);

    unsigned int get_x()
    {
        return x;
    }

    unsigned int get_y()
    {
        return y;
    }


private:
    unsigned int x;
    unsigned int y;
};







#endif // FRAME_H
