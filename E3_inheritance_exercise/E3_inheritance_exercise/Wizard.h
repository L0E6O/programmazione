//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_WIZARD_H
#define E3_INHERITANCE_EXERCISE_WIZARD_H

#include <string>

#include "GameCharacter.h"

class Wizard : public GameCharacter {

public:

        explicit Wizard(int hp=10, int a=5, std::string n="ciccio", int m=5): GameCharacter(hp, a), name(n), mana(m){}

        int fight(GameCharacter &enemy) override;

        // in this class do not override move()

        // in derived classes we can introduce new behaviours, like this brand new method:
        virtual void doMagic(); // it's virtual: we expect to further derive and override its behaviour in derived classes

        // override base class method
        char getCharacterSymbol() const {
            return 'W';
        }

protected:
    int mana; // spiritual strength
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_WIZARD_H
