//
// Created by jarro on 23/06/26.
//

#ifndef ENEMIES_OGRE_H
#define ENEMIES_OGRE_H
#include <string>

#include "Enemy.h"


class Ogre : public Enemy {
public:
    Ogre(std::string n, const int h, const int d) : Enemy(std::move(n), h), damage(d) {}

    int calculate_damage() const override;

private:
    int damage;
};



#endif //ENEMIES_OGRE_H
