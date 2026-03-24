//
// Created by Marco Bertini on 08/04/18.
//

#include "Wizard.h"

#include <iostream>


void Wizard::doMagic() {
    if (mana > 1) {
        std::cout << "You heal for 1HP! Current mana: " << mana-- << std::endl;
        setHP(getHP() + 1);
    }

}

int Wizard::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = GameCharacter::fight(enemy);
    if (mana > 20) {
        damage *= 1.2;
        mana--;
    } else if (mana > 10)
        damage += 2;
    return damage;
}
