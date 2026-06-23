//
// Created by jarro on 23/06/26.
//

#ifndef ENEMIES_ENEMY_H
#define ENEMIES_ENEMY_H
#include <iostream>
#include <string>


class Enemy {
public:
    virtual ~Enemy() = default;

    Enemy(std::string n, const int h) : name(std::move(n)), hp(h) {}

    virtual void print() const;

    virtual int calculate_damage() const = 0;

protected:
    std::string name;
    int hp;
};


#endif //ENEMIES_ENEMY_H
