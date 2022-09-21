#include "widget.h"
#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>
#include <Qdebug>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game game;

    game.resize(game_size_x, game_size_y);

    game.init_frame_to_game();
    game.init_snake_to_game();

    game.show();

    return a.exec();
}
