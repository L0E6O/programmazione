#include "GameApp.h"

int main() {
    GameApp game;

    game.renderHUD();
    while (game.isOpen()) {
        // poll event
        GameEvent gameEvent = game.getEvent();

        // update game status
        bool quit = game.updateGame(gameEvent);
        if (quit)
            return 0;
    }
}
