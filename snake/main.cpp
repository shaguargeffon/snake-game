#include "widget.h"
#include <QApplication>
#include <QKeyEvent>
#include <QMouseEvent>
#include <Qdebug>
#include <iostream>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();





    Game *game = new Game();




    game->show();

    return a.exec();
}
