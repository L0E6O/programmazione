//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_SKELETON_H
#define E3_INHERITANCE_EXERCISE_SKELETON_H
#include "GameCharacter.h"


class Skeleton : public GameCharacter {
public:
    Skeleton(int hp, int a, int mR): GameCharacter(hp, a), magicRecover(mR){}

    int receiveDamage(int points) override;
    // XXX it's already implemented in .cpp file

    // XXX no need to override other base class methods in this class

    // override base class method
    char getCharacterSymbol() const override{
        return 'S';
    }

private:
    bool magicRecover;
};


#endif //E3_INHERITANCE_EXERCISE_SKELETON_H
