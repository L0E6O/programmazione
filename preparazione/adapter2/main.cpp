#include <iostream>
#include <memory>

enum class Buttons {A, B, X, Y};
enum class Directions {up, down, left, right};

class Player {
public:
    void processDirection(const Directions d) const {
        std::cout << "Moving ";
        switch (d) {
            case Directions::up :
                std::cout << "up";
                break;
            case Directions::down :
                std::cout << "down";
                break;
            case Directions::left :
                std::cout << "left";
                break;
            case Directions::right :
                std::cout << "right";
                break;
        }
        std::cout << "!" << std::endl;
    }
};

class Controller {
public:

    virtual ~Controller() = default;

    virtual void press(const Buttons b) const {
        std::cout << "Pressed: ";
        switch (b) {
            case Buttons::A :
                std::cout << "A";
                break;
            case Buttons::B :
                std::cout << "B";
                break;
            case Buttons::X :
                std::cout << "X";
                break;
            case Buttons::Y :
                std::cout << "Y";
                break;
        }
        std::cout << std::endl;
    }
};

class ControllerAdapter : public Controller {
public:

    ControllerAdapter(std::unique_ptr<Player> p) : player(std::move(p)) {}

    void press(const Buttons b) const override{
        Directions d;
        switch (b) {
            case Buttons::A :
                d = Directions::up;
                break;
            case Buttons::B :
                d = Directions::down;
                break;
            case Buttons::X :
                d = Directions::left;
                break;
            case Buttons::Y :
                d = Directions::right;
                break;
        }
        player->processDirection(d);
    }

private:
    std::unique_ptr<Player> player;
};

int main() {
    auto player = std::make_unique<Player>();
    std::unique_ptr<Controller> controller = std::make_unique<Controller>();
    auto adapter = std::make_unique<ControllerAdapter>(std::move(player));

    controller->press(Buttons::B);
    adapter->press(Buttons::B);

    return 0;
}