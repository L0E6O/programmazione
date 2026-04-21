#ifndef E3_INHERITANCE_EXERCISE_SWORD_H
#define E3_INHERITANCE_EXERCISE_SWORD_H

#include "Weapon.h"

class Sword : public Weapon {
public:
    explicit Sword(int s, bool m = false, bool v = false);

    int use() override;

    Sword* clone() override;

    bool isValirian() const {
        return valirian;
    }

    void setValirian(bool valirian) {
        Sword::valirian = valirian;
    }

protected:
    bool valirian;
};


#endif //E3_INHERITANCE_EXERCISE_SWORD_H
