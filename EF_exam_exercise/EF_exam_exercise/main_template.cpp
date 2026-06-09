#include <iostream>

template<typename T>
class Point {
public:
    Point(T x=0, T y=0) : x(x), y(y) {} //XXX qui va bene, ma in certi template, 0 potrebbe NON andare bene per certi tipi!!!

    bool operator==(const Point<T>& other) {
        return this->x == other.x && this->y == other.y;
    }

    Point<T> operator+(const Point<T>& other) {
        return Point<T>(this->x + other.x, this->y + other.y);
    }

    Point<T> operator-(const Point<T>& other) {
        return Point<T>(this->x - other.x, this->y - other.y);
    }

    T getX() const {
        return x;
    }

    T getY() const {
        return y;
    }

private:
    T x, y;
};

int main() {
    Point<int> intPoint1(10, 10);
    Point<int> intPoint2(14, 0);
    Point<float> flPoint1(1.23);
    Point<float> flPoint2(6.89, 9.11);

    Point<float> flPoint3 = flPoint1 + flPoint2;

    std::cout << "X=" << flPoint3.getX() << "Y=" << flPoint3.getY() << std::endl;

    flPoint3 = flPoint3 - flPoint2;

    std::cout << "X=" << flPoint3.getX() << "Y=" << flPoint3.getY() << std::endl;

    std::cout << (intPoint1 == intPoint2) << std::endl;
    std::cout << (intPoint1 == intPoint1) << std::endl;
}
