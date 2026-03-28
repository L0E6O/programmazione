/*
 * Character.h
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Weapon.h"

class GameCharacter {
public:
    GameCharacter();
    explicit GameCharacter(int hp, int a = 10);

    virtual ~GameCharacter();

    GameCharacter(const GameCharacter &original);
    GameCharacter &operator=(const GameCharacter &right);

    virtual void move(int x, int y); //virtual si mette sui metodi polimorfici. ESEMPIO: con virtual il compilatore avrà del codice creato in runtime che in diretta vedra a cosa punta weapon (bow o sword) e userà lo use adatto (altrimenti avendo i puntatori, userebbe use di Weapon). Lo stato di virtual si eredita


    virtual char getCharacterSymbol() const {
        return 'C';
    }

    virtual int fight(GameCharacter &enemy);
    bool isLegalFight(const GameCharacter &enemy) const;

    virtual int receiveDamage(int points);

    static int l1Distance(const GameCharacter& p, const GameCharacter& q);

    int getPosX() const {
        return posX;
    }
    void setPosX(int posX) {
        GameCharacter::posX = posX;
    }

    int getPosY() const {
        return posY;
    }
    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    int getHP() const;
    void setHP(int hp);

    Weapon* getWeapon();
    void setWeapon(Weapon* weapon);

    int getArmor() const;
    void setArmor(int defense);

    int getMovements() const;
    void setMovements(int movements);

protected:
    int HP;
    int armor;
    int movements;
    int posX;
    int posY;
    Weapon* weapon;
};

#endif // CHARACTER_H_
