#ifndef MOVEMENT_MANAGER_H
#define MOVEMENT_MANAGER_H

#include "snake.h"
#include "frame.h"
#include <vector>


class MovementManager
{
public:
    MovementManager(unsigned int pos_x, unsigned int pos_y): x(pos_x), y(pos_y)
    {

    }


private:
    std::vector<Snake*> snakes;
    std::vector<Frame*> frames;

};







#endif // MOVEMENT_MANAGER_H
