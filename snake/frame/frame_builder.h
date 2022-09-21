#ifndef FRAME_BUILDER_H
#define FRAME_BUILDER_H

#include "config.h"
#include "frame.h"
#include "frame_layout.h"
#include "widget.h"


class FrameBuilder
{
public:
    FrameBuilder(FrameLayout* f, Game &w)
    {
        f->build_layout();

        for(auto it=f->get_layout().begin(); it!=f->get_layout().end(); it++)
        {
            unsigned int x{start_point_coordinate_x};
            unsigned int y{start_point_coordinate_y};

            x+=(element_size_x)*((*it)->get_x());
            y+=(element_size_y)*((*it)->get_y());

            std::shared_ptr<Frame> frame_p(new Frame(x, y));

            frame_p->setParent(&w);

            frame_p->move(x, y);

            frame_p->resize(element_size_x, element_size_y);

            frame_p->setStyleSheet("background-color: black");

            frame_layout.push_back(frame_p);

            frame_p->show();
        }

    }


private:
    std::vector<std::shared_ptr<Frame>> frame_layout;

};


#endif // FRAME_BUILDER_H
