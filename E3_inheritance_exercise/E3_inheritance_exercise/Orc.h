//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_ORC_H
#define E3_INHERITANCE_EXERCISE_ORC_H
#include "GameCharacter.h"

class Orc : public GameCharacter {
public:
    int fight(GameCharacter &enemy) override;

    void move(int x, int y) override;

    // override base class method
    char getCharacterSymbol() const override{
        return 'O';
    }

protected:
    int strength;
};


#endif //E3_INHERITANCE_EXERCISE_ORC_H
