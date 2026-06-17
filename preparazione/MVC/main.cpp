// Exercise - MVC pattern (10+2+2 points)
// You are building a simple temperature monitoring app following MVC.
// The Model (TemperatureModel) holds the current temperature and notifies
// observers when it changes (you can reuse the Observer pattern internally).
// The View (TemperatureView) displays the temperature whenever it's updated.
// The Controller (TemperatureController) is the only component allowed to
// modify the Model, based on simulated "user input".
//
// The function runApp() (which cannot be modified) wires everything together
// and simulates a few temperature changes through the controller.
//
// Implement Model, View and Controller respecting MVC responsibilities:
// the View must NEVER modify the Model directly, and the Controller must
// NEVER directly call View methods (10 points).
// Make TemperatureView implement an Observer interface so it gets notified
// automatically when the Model changes (2 points).
// Add a second view (TemperatureAlertView) that only prints a warning when
// the temperature exceeds a threshold, and show that both views update
// independently when the Model changes (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(double temp) const = 0;
};

class TemperatureView : public Observer {
public:
    void update(double temp) const override {
        std::cout << "Temperature is now: " << temp << std::endl;
    }
};

class TemperatureAlert : public Observer {
public:
    TemperatureAlert(double t) : threshold(t) {}

    void update(double temp) const override {
        if (temp > threshold)
            std::cout << "Temperature alert: " << temp << std::endl;
    }
private:
    double threshold;
};

class TemperatureModel {
public:
    void attach(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void detach(const std::shared_ptr<Observer>& obs) {
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i].get() == obs.get()) {
                observers.erase(observers.begin() + i);
                return;
            }
        }
        std::cout << "Observer is not observing" << std::endl;
    }

    void notify(double t) {
        for (const auto& observer : observers) {
            observer->update(t);
        }
    }

    void setTemperature(double t) {
        temperature = t;
        notify(t);
    }

    double getTemperature() const {
        return temperature;
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
    double temperature;
};

class TemperatureController {
public:
    TemperatureController(const std::shared_ptr<TemperatureModel>& m) : model(m) {}

    void simulateSensorReading(const double temp) const {
        model->setTemperature(temp);
    }

private:
    std::shared_ptr<TemperatureModel> model;
};

// DO NOT MODIFY
void runApp(TemperatureModel& model, TemperatureController& controller) {
    controller.simulateSensorReading(20.0);
    controller.simulateSensorReading(35.0);
    controller.simulateSensorReading(15.0);
}

int main() {
    // TODO create model, attach a TemperatureView and a TemperatureAlertView(threshold=30)
    // create controller, call runApp()
    auto model = std::make_shared<TemperatureModel>();
    auto view = std::make_shared<TemperatureView>();
    auto alert = std::make_shared<TemperatureAlert>(30.0);

    model->attach(view);
    model->attach(alert);

    auto controller = std::make_unique<TemperatureController>(model);

    runApp(*model, *controller);

    model->detach(view);

    runApp(*model, *controller);

    return 0;
}