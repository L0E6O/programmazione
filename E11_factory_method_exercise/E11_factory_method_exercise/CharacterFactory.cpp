#include "CharacterFactory.h"
#include "Wizard.h"
#include "Knight.h"
#include <iostream>

CharacterFactory::CharacterFactory() {
    // ...
    std::cout << "Loading bitmap resources..." << std::endl;
    charactersBitmap = new unsigned char[10 * bitmapSize];
}

CharacterFactory::~CharacterFactory() {
    // ...
    delete[] charactersBitmap;
}

unsigned char* CharacterFactory::getBitmapTile(CharacterType type) {
    if (type == CharacterType::Knight) {
        return charactersBitmap; // XXX would return something from charactersBitmap
    } else {
        return charactersBitmap+bitmapSize; // XXX would return something from charactersBitmap
    }
}

std::unique_ptr<GameCharacter> CharacterFactory::createCharacter(CharacterType type) {
    std::unique_ptr<GameCharacter> result;
    if (type == CharacterType::Knight) {
        result = std::make_unique<Knight>();
    } else {
        result = std::make_unique<Wizard>();
    }
    result->setBitmap(getBitmapTile(type), bitmapSize);
    return result;
}