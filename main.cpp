#include "Game.h"
#include "stdafx.h"

int main() {
    Game game;
    while(game.getWindow().isOpen()){ // Loop to update and render the game while is open
        game.update();
        game.render();
    }

    return 0;
}

