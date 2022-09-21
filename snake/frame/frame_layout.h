#ifndef FRAME_LAYOUT_H
#define FRAME_LAYOUT_H

#include "frame.h"
#include <vector>
#include <memory>

class FrameLayout
{
public:
    FrameLayout() = default;

    void build_layout()
    {
        unsigned int i{0};
        unsigned int j{0};

        //Generate above frame
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout.push_back(p);
        }

        //Generate bottom frame
        j = frame_amount_y - 1;
        for(i = 0; i<frame_amount_x; i++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout.push_back(p);
        }


        //Generate left frame
        i = 0;

        for(j = 0; j<frame_amount_y-1; j++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout.push_back(p);
        }


        //Generate right frame
        i = frame_amount_x - 1;

        for(j = 0; j<frame_amount_y-1; j++)
        {
            std::shared_ptr<Frame> p(new Frame(i, j));
            frame_layout.push_back(p);
        }

    }


    std::vector<std::shared_ptr<Frame>>& get_layout()
    {
        return frame_layout;
    }

    ~FrameLayout() = default;

private:
    std::vector<std::shared_ptr<Frame>> frame_layout;
};




#endif // FRAME_LAYOUT_H
