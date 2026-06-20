#include <iostream>
#include <memory>
#include <vector>

class Observer {
public:

    virtual ~Observer() = default;

    virtual void update(int num) = 0;
};

class Shouter : public Observer {
public:
    Shouter(int t) : treshold(t) {}

    void update(int num) override {
        std::cout << "AAAAAAAAH THE NEW NUMBER IS: " << num << (num > treshold ? " IT'S ABOVE THRESHOLD!!!" : "") << std::endl;
    }
private:
    int treshold;
};

class Controller;

class Buffer {
public:
    friend class Controller;

    void addObserver(std::shared_ptr<Observer> ob) {
        observers.push_back(std::move(ob));
    }

    void removeObserver(std::shared_ptr<Observer> ob) {
        for (int i = 0; i < observers.size();) {
            if (observers[i] == ob) {
                observers.erase(observers.begin() + i);
                break;
            }

            i++;
        }
    }

private:
    int number;
    std::vector<std::shared_ptr<Observer>> observers;

    void setNumber(int num) {
        number = num;
        notify();
    }

    void notify() {
        for (const auto& observer : observers) {
            observer->update(number);
        }
    }
};

class Controller {
public:
    Controller(Buffer* m) : model(m) {}

    void changeNumber(int n) {
        model->setNumber(n);
    }
private:
    Buffer* model;
};

int main() {
    std::shared_ptr<Observer> ob1 = std::make_shared<Shouter>(5);
    std::shared_ptr<Observer> ob2 = std::make_shared<Shouter>(10);
    auto buffer = std::make_unique<Buffer>();
    auto controller = std::make_unique<Controller>(buffer.get());
    buffer->addObserver(ob1);
    controller->changeNumber(3);
    controller->changeNumber(6);
    buffer->addObserver(ob2);
    controller->changeNumber(9);
    buffer->removeObserver(ob1);
    controller->changeNumber(8);
    return 0;
}