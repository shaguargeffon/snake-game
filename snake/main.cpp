#include "widget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    get_app_pointer(&app);

    Game game;

    game.resize(game_size_x, game_size_y);

    game.init_frame_to_game();
    game.init_snake_to_game();

    game.show();

    return app.exec();
}
