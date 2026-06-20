
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class MeanOfTransportation {
public:

    MeanOfTransportation(std::string s) : name(std::move(s)) {}

    virtual ~MeanOfTransportation() = default;

    virtual void printInfo() const = 0;
protected:
    std::string name;
};

class Ship : public MeanOfTransportation {
public:
    Ship(std::string s) : MeanOfTransportation(std::move(s)) {}

    void printInfo() const override {
        std::cout << "Ship name: " << name << std::endl;
    }

    void sail() const {
        std::cout << "Ship has sailed" << std::endl;
    }
};

class Aeroplane : public MeanOfTransportation {
public:
    Aeroplane(std::string s) : MeanOfTransportation(std::move(s)) {}

    void printInfo() const override {
        std::cout << "Plane name: " << name << std::endl;
    }

    void takeOff() const {
        std::cout << "Plane has taken off" << std::endl;
    }
};

void depart(const std::vector<std::shared_ptr<MeanOfTransportation>>& means) {
    for (const auto& mean : means) {
        if (auto ship = dynamic_cast<Ship*>(mean.get()))
            ship->sail();
        else if (auto plane = dynamic_cast<Aeroplane*>(mean.get()))
            plane->takeOff();
    }
}

int main() {

    std::shared_ptr<MeanOfTransportation> plane = std::make_shared<Aeroplane>("Plano");
    std::shared_ptr<MeanOfTransportation> ship = std::make_shared<Ship>("Nave");
    std::vector<std::shared_ptr<MeanOfTransportation>> means;
    means.push_back(plane);
    means.push_back(ship);
    plane->printInfo();
    depart(means);

    return 0;
}