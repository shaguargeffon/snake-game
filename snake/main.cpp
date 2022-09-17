#include "widget.h"
#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>
#include <Qdebug>
#include <iostream>
#include "frame_builder.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    Game game;

    game.resize(game_size_x, game_size_y);

    FrameLayout frame_layout;
    FrameBuilder f_builder(&frame_layout, game);

    game.show();

    return a.exec();
}
