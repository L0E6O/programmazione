//
// Created by jarro on 23/06/26.
//

#ifndef ENEMIES_DRAGON_H
#define ENEMIES_DRAGON_H
#include <algorithm>

#include "Enemy.h"


class Dragon : public Enemy {
public:
    Dragon(std::string n, const int h, const int d, const int b) : Enemy(std::move(n), h), damage(d), bonus(b) {}

    int calculate_damage() const override;

private:
    int damage;
    int bonus;
};


#endif //ENEMIES_DRAGON_H
