// Exercise - Casting (10+2+2 points)
// You are working on a drawing application. Shapes are stored in a list of
// Shape pointers. The function printAll() (which cannot be modified) prints
// a description of each shape.
//
// Some shapes are Resizable (they expose a resize() method), others are not.
// The function resizeAll() (which cannot be modified) tries to resize every
// shape in the list, but only if it actually supports resizing.
//
// Implement the class hierarchy (10 points).
// Use dynamic_cast correctly in resizeAll() to attempt the cast safely,
// and print a message if a shape is not resizable (2 points).
// Add a third shape type ColoredCircle that inherits from both Circle
// and a Colorable interface, and show how to cast to it (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

// TODO implement:
//   - abstract class Shape with virtual describe() and virtual destructor
//   - interface Resizable with virtual resize(float factor)
//   - class Circle : public Shape (has radius)
//   - class ResizableRect : public Shape, public Resizable (has width, height)
//   - class ColoredCircle : public Circle, public Colorable (bonus)

class Shape {
public:
    Shape() = default;

    virtual ~Shape() = default;
    virtual void describe() const = 0;
};

class Resizable {
public:
    virtual void resize(float factor) = 0;

    virtual ~Resizable() = default;
};

class Colorable {
public:
    Colorable(std::string color) : color(std::move(color)) {}

    virtual ~Colorable() = default;

    virtual void changeColor(std::string c) {
        color = c;
    }

private:
    std::string color;
};

class Circle : public Shape{
public:
    Circle(double radius) : radius(radius) {}

    void describe() const override {
        std::cout << "Radius: " << radius << std::endl;
    }

private:
    double radius;
};

class ColoredCircle : public Circle, public Colorable {
public:
    ColoredCircle(double radius=1, std::string color="none") : Circle(radius), Colorable(std::move(color)) {}
};

class ResizableRect : public Shape, public Resizable {
public:

    ResizableRect(double width, double height) : width(width), height(height) {}

    void describe() const override {
        std::cout << "Width: " << width << "\nHeight: " << height << std::endl;
    }

    void resize(float factor) override {
        width *= factor;
        height *= factor;
    }

private:
    double width;
    double height;
};

// DO NOT MODIFY
void printAll(const std::vector<std::shared_ptr<Shape>>& shapes) {
    for (const auto& s : shapes)
        s->describe();
}

// DO NOT MODIFY
void resizeAll(const std::vector<std::shared_ptr<Shape>>& shapes, float factor) {
    for (const auto& s : shapes) {
        auto resizable = dynamic_cast<Resizable*>(s.get());
        if (resizable!=nullptr)
            resizable->resize(factor);
        else
            std::cout << "Shape not resizable!" << std::endl;
    }
}

void colorAll(const std::vector<std::shared_ptr<Shape>>& shapes, const std::string& color) {
    for (const auto& s : shapes) {
        auto colorable = dynamic_cast<Colorable*>(s.get());
        if (colorable!=nullptr)
            colorable->changeColor(color);
    }
}

int main() {
    // TODO populate a vector with Circle and ResizableRect,
    // call printAll() and resizeAll()
    // show the dynamic_cast failure case too
    return 0;
}