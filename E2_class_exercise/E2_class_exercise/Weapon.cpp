//
// Created on: 13/mar/2018
// Author: bertini
//

#include "Weapon.h"

Weapon::Weapon(int s, bool m): strength(s), magic(m) {
    if (s <= 0)
        strength = DEFAULT_STRENGHT;
}

int Weapon::use() const {
    int result = strength;
    if (magic)
        result *= 2;
    return result;
}