#include "Wizard.h"

#include <iostream>


void Wizard::doMagic() {
    if (mana > 1) {
        std::cout << "Healing spell! (+10HP)" << std::endl;
        HP += 10;
        mana--;
    }
}

int Wizard::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = basicFight(enemy);
    if (mana > 20) {
        damage *= 1.2;
        mana--;
    } else if (mana > 10)
        damage += 2;
    return damage;
}
