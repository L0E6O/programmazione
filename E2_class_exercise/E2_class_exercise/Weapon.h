//
// Created on: 13/mar/2018
//  Author: bertini
//

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(): Weapon(DEFAULT_STRENGHT, false){} //dieci scelto a piacere

    explicit Weapon(int s, bool m = false);

    int use() const;

    void setStrength(int s) {
        strength = s;
    }

    int getStrength() const {
        return strength;
    }

    void setMagic(bool m) {
        magic = m;
    }

    bool isMagic() const {
        return magic;
    }

protected:
    int strength;
    bool magic;
    static const int DEFAULT_STRENGHT = 10;
};

#endif // WEAPON_H
