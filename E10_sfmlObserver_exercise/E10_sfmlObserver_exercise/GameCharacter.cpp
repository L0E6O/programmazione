#include "GameCharacter.h"

GameCharacter::GameCharacter() : posX(0), posY(0) {
    // ... more code ...
}

GameCharacter::~GameCharacter() {
    // ... more code ...
}

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
}

