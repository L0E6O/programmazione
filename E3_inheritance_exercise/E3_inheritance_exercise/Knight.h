//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_KNIGHT_H
#define E3_INHERITANCE_EXERCISE_KNIGHT_H

#include <string>

#include "GameCharacter.h"

// extend GameCharacter
class Knight : public GameCharacter{
public:
    explicit Knight(int hp=10, int a=5, int d=15, bool p=false, std::string n="ciccio") : GameCharacter(hp, a), dexterity(d), paladin(p), name(n){}

    int fight(GameCharacter &enemy) override;

    void move(int x, int y) override;

    char getCharacterSymbol() const override {
        return 'K';
    }

private:
    int dexterity;
    bool paladin;
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_KNIGHT_H
