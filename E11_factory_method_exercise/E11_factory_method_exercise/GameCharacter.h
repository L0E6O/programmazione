#ifndef FACTORY_METHOD_GAMECHARACTER_H
#define FACTORY_METHOD_GAMECHARACTER_H

#include <cstring>
#include <iostream>

class GameCharacter {
public:
    GameCharacter() : posX(0), posY(0), HP(10) {
        bitmap = new unsigned char[4096];
    }
    virtual ~GameCharacter() {
        if (bitmap)
            delete[] bitmap;
    }

    virtual void move(int x, int y) = 0;
    virtual void fight(GameCharacter& enemy) = 0;

    virtual void draw() {
        std::cout << "Draw bitmap at: " << &bitmap << std::endl;
    }
    void setBitmap(const unsigned char* b, int size) {
       memcpy(bitmap, b, size);
    }

protected:
    int posX, posY;
    int HP;

    unsigned char* bitmap;
};


#endif //FACTORY_METHOD_GAMECHARACTER_H
