#ifndef LAYOUT_H
#define LAYOUT_H

#include <QPushButton>
#include "layout_config.h"




class Frame: public QPushButton
{
public:
    Frame(unsigned int pos_x, unsigned int pos_y): x(pos_x), y(pos_y)
    {

    }


private:
    unsigned int x;
    unsigned int y;
};







#endif // LAYOUT_H
