#include <iostream>
#include "Game.h"

int main()
{
    Game game;
    game.startGame();

    while (!game.gameOver())
    {
        game.startTurn();
        game.endTurn();
    }

    game.endGame();

    return 0;
}
