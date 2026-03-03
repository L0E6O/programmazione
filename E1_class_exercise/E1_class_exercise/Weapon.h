#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon(int s, bool magic = false) : strength(s), magic(magic) {
        //magic is false by default
        if (strength <= 0)
            strength = 1;
    }

    int use();

    int getStrength() const {
        return strength;
    }

    void setStrength(int s) {
        if (s > 0)
            strength = s;
    }

    bool isMagic() const {
        return magic;
    }

    void setMagic(bool m) {
        magic = m;
    }

protected:
    int strength;
    bool magic;
};

#endif //WEAPON_H
