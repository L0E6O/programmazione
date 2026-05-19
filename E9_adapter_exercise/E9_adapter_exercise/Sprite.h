#ifndef SPRITE_H
#define SPRITE_H

#include "Shape.h"
#include <string>

class Sprite : public Shape {
public:
    explicit Sprite(std::string fileN, int w=100, int h=200) :
            width(w), height(h), fileName(fileN) {}
    virtual ~Sprite() {}

    virtual void draw() override;
    virtual void resize(float newSize) override;

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        Sprite::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Sprite::height = height;
    }

    const std::string &getFileName() const {
        return fileName;
    }

    void setFileName(const std::string &fileName) {
        Sprite::fileName = fileName;
    }

private:
    int width, height;
    std::string fileName;
};


#endif //CSPRITE_H
