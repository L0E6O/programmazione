#ifndef OBSERVER_GAMECHARACTER_H
#define OBSERVER_GAMECHARACTER_H
#include "Subject.h"


// TODO change as needed
class GameCharacter : public Subject{
public:

    GameCharacter();
    virtual ~GameCharacter();

    void subscribe(Observer* observer) override{
        //TODO completa
        observers.push_back(observer);
    }

    void unsubscribe() override {
        //TODO fai
    }

    void notify() override {
        //TODO fai
    }

    void move(int x, int y);

    int getPosX() const {
        return posX;
    }
    void setPosX(int posX) {
        this->posX = posX;
    }
    int getPosY() const {
        return posY;
    }
    void setPosY(int posY) {
        this->posY = posY;
    }

private:
    int posX, posY;
};


#endif //OBSERVER_GAMECHARACTER_H
