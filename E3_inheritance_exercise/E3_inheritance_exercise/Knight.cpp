//
// Created by Marco Bertini on 08/04/18.
//

#include "Knight.h"
#include "Dice.h"

int Knight::fight(GameCharacter &enemy) {
    Dice myDice(6);

    int hit = 1;
    int attacks = (dexterity > 10) ? 2 : 1;
    do {
        if (weapon)
            hit = weapon->use();

        if (paladin)
            hit += 10;
    } while (--attacks > 0);

    int damage = 0;
    int hitChance = myDice.roll(2);
    if (hitChance > 4) { // OK we can hit
        hit += myDice.roll(1); // additional random damage
        if (hit > enemy.getArmor()) {
            damage = enemy.receiveDamage(hit);
        }
    }

    return damage;
}

void Knight::move(int x, int y) {
    GameCharacter::move(x, y);
    if (dexterity > 10)
        GameCharacter:move(x, y);
}
