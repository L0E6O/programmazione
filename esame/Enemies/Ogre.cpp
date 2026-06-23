//
// Created by jarro on 23/06/26.
//

#include "Ogre.h"

int Ogre::calculate_damage() const {
    return hp < 10 ? damage * 2 : damage;
}
