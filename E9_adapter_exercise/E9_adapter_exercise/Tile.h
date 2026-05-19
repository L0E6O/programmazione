#ifndef TILE_H
#define TILE_H

#include "Shape.h"
#include <string>

class Tile : public Shape {
public:
    explicit Tile(std::string fileN, int t=1, int d=50) :
            type(t), dim(d), fileName(fileN) {}
    virtual ~Tile() {}

    virtual void draw() override;
    virtual void resize(float newSize) override;

    int getType() const {
        return type;
    }

    void setType(int type) {
        Tile::type = type;
    }

    int getDim() const {
        return dim;
    }

    void setDim(int dim) {
        Tile::dim = dim;
    }

    const std::string &getFileName() const {
        return fileName;
    }

    void setFileName(const std::string &fileName) {
        Tile::fileName = fileName;
    }

private:
    int type;
    int dim;
    std::string fileName;
};


#endif //TILE_H
