/*
 * Character.cpp
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#include "GameCharacter.h"

#include <ctime>
#include <iostream>
#include <tuple>

#include "Dice.h"

using namespace std;
static const int DEFAULT_HP = 10;
GameCharacter::GameCharacter(int hp, int a): HP(hp), armor(a), posX(0), posY(0), weapon(nullptr){}

int GameCharacter::getHP() const {
    return HP;
}

void GameCharacter::setHP(int hp) {
    this->HP = hp;
}

Weapon* GameCharacter::getWeapon() const {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
}

void GameCharacter::move(int distance) {
    posX += distance;
    posY += distance;
}

int GameCharacter::getArmor() const {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter &enemy) const{
    bool success = false;
    Dice d6(6);
    int rollResult = d6.roll(1);

    int hit = 1;
    if (weapon)
        hit = weapon->use();

    int damage = 0;
    if (hit > enemy.getArmor()) {
        cout << "Roll result: " << rollResult << endl;
        if (rollResult >= 3)
            damage = enemy.receiveDamage(hit);
    }

    if (damage) {
        cout << "You hit the enemy ! (HP: " << enemy.getHP() << " punti)" << endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

int GameCharacter::receiveDamage(int points) {
    if (armor > 4)
        points /= 3;
    else if (armor > 2)
        points /= 2;
    else if (armor >= 1)
        points -= 2;

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}


bool GameCharacter::isLegalFight(const GameCharacter &enemy) const {
    int maxDistance = 1;
    if ((abs(posX - enemy.posX) > maxDistance) || (abs(posY - enemy.posY) > maxDistance))
        return false;
    return true;
}

static int l1Dist(const GameCharacter &a, const GameCharacter &b) {
    return (abs(a.getPosX() - b.getPosX()) + abs(a.getPosY() - b.getPosY()));
}