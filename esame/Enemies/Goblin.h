//
// Created by jarro on 23/06/26.
//

#ifndef ENEMIES_GOBLIN_H
#define ENEMIES_GOBLIN_H
#include "Enemy.h"


class Goblin : public Enemy {
public:
    Goblin(std::string n, const int h, const int d) : Enemy(std::move(n), h), damage(d) {}

    int calculate_damage() const override;

private:
    int damage;
};

#endif //ENEMIES_GOBLIN_H
