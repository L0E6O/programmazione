#include "Bow.h"

Bow::Bow(int strength, int ar, bool magic) : Weapon(strength, magic), arrows(ar) {

}

Bow* Bow::clone() {
    return new Bow(*this);
}

int Bow::use() {
    int totalDamage;
    if (arrows) {
        totalDamage = basicUse();
        arrows--;
    }
    return totalDamage;
}