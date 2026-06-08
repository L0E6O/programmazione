#include <iostream>
#include "GameCharacter.h"
#include "CharacterFactory.h"

int main() {
    CharacterFactory* characterFactory = new CharacterFactory();

    auto hero = characterFactory->createCharacter(CharacterType::Knight);
    auto enemy = characterFactory->createCharacter(CharacterType::Knight);

    hero->draw();
    enemy->draw();
    hero->move(1, 1);
    hero->fight(*enemy);
    enemy->move(2, 2);

    // XXX without smart pointers this code will leak... manual memory mgmt. required

    return 0;
}
