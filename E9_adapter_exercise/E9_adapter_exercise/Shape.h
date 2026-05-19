#ifndef ADAPTER_SHAPE_H
#define ADAPTER_SHAPE_H

class Shape {
public:
    explicit Shape(int ax=0, int ay=0) : x(ax), y(ay) {}
    virtual ~Shape() {}

    virtual void draw() = 0;
    virtual void resize(float newSize) = 0;

    int getX() const {
        return x;
    }

    void setX(int x) {
        Shape::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Shape::y = y;
    }

protected:
    int x, y;
};

#endif //ADAPTER_SHAPE_H
