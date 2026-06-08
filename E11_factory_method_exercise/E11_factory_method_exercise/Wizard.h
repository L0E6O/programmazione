#ifndef FACTORY_METHOD_WIZARD_H
#define FACTORY_METHOD_WIZARD_H

#include "GameCharacter.h"

class Wizard : public GameCharacter {
public:
    Wizard() {}
    virtual ~Wizard() {}

    virtual void move(int x, int y) override;
    virtual void fight(GameCharacter& enemy) override;

};


#endif //FACTORY_METHOD_WIZARD_H
