#include <iostream>

#include "Game.h"

using namespace std;
using namespace game;

int main(int argc, char const *argv[])
{
    Game game = Game();
    while (game.isRunning()) {
        game.update();
    }
    return 0;
}