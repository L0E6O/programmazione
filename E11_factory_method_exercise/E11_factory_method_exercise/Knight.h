#ifndef FACTORY_METHOD_KNIGHT_H
#define FACTORY_METHOD_KNIGHT_H

#include "GameCharacter.h"

class Knight : public GameCharacter {
public:
    Knight() : dexterity(1) { }
    virtual ~Knight() {}

    virtual void move(int x, int y) override;
    virtual void fight(GameCharacter& enemy) override;

private:
    int dexterity;
};


#endif //FACTORY_METHOD_KNIGHT_H
