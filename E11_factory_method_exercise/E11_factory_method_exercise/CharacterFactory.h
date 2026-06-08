#ifndef FACTORY_METHOD_CHARACTERFACTORY_H
#define FACTORY_METHOD_CHARACTERFACTORY_H

#include <memory>
#include "GameCharacter.h"

enum class CharacterType {Knight, Wizard}; // C++11 named enum

class CharacterFactory {
public:
    CharacterFactory();
    virtual ~CharacterFactory();

    unsigned char* getBitmapTile(CharacterType type);

    virtual std::unique_ptr<GameCharacter> createCharacter(CharacterType type);

private:
    unsigned char* charactersBitmap;
    const int bitmapSize = 4096;
};

#endif //FACTORY_METHOD_CHARACTERFACTORY_H
