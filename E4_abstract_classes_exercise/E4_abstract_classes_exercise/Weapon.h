#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon();
    explicit Weapon(int s, bool m = false);
    virtual ~Weapon() {} // XXX polymorphic destructor !

    virtual int use() = 0; //XXX '= 0' rende il metodo PURAMENTE VIRTUALE

    virtual Weapon* clone() = 0;

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

    virtual int basicUse();
};

#endif // WEAPON_H
