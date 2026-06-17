// Exercise - Observer pattern (10+2+2 points)
// You are building a simple stock market tracker. The class StockMarket
// holds the current price of a stock and notifies all subscribed observers
// whenever the price changes.
//
// The function simulateTrading() (which cannot be modified) creates a
// StockMarket, attaches some observers, and triggers a few price changes.
//
// Implement the Observer pattern: an abstract Observer interface with
// onPriceChanged(), and StockMarket as the Subject that manages a list
// of observers and notifies them (10 points).
// Implement two concrete observers: PriceLogger (prints every change) and
// PriceAlert (prints a warning only if the price drops below a threshold) (2 points).
// Allow an observer to unsubscribe (detach) from the StockMarket (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>

// TODO implement:
//   - abstract class Observer with virtual onPriceChanged(double newPrice)
//   - class StockMarket (Subject) with:
//       void attach(std::shared_ptr<Observer> obs)
//       void detach(std::shared_ptr<Observer> obs)
//       void setPrice(double price)   // notifies all observers
//   - class PriceLogger : public Observer
//   - class PriceAlert : public Observer (takes a threshold in constructor)

class StockMarket;

class Observer {
public:

    virtual ~Observer() = default;

    virtual void update(double newPrice) = 0;
};

class PriceLogger : public Observer{
public:
    void update(double newPrice) override {
        std::cout << "NUOVO PREZZO: " << newPrice << std::endl;
    }
};

class PriceAlert : public Observer {
public:

    PriceAlert(const double t) : threshold(t) {}

    void update(double newPrice) override {
        if (newPrice < threshold)
            std::cout << "ALLERTA PREZZO: " << newPrice << std::endl;
    }

private:
    double threshold;
};

class StockMarket {
public:
    void attach(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }

    void detach(const std::shared_ptr<Observer>& obs) {
        int index = -1;
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i].get() == obs.get()) {
                index = i;
                break;
            }
        }
        if (index != -1)
            observers.erase(observers.begin() + index);
        else
            std::cout << "Observer is not observing" << std::endl;
    }

    void setPrice(double p) {
        price = p;
        notify();
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
    double price;

    void notify() const {
        for (const auto& observer : observers) {
            observer->update(price);
        }
    }
};

// the function that drives the simulation: DO NOT MODIFY
void simulateTrading(StockMarket& market) {
    market.setPrice(100.0);
    market.setPrice(95.0);
    market.setPrice(80.0);
    market.setPrice(120.0);
}

int main() {
    StockMarket market;
    auto logger = std::make_shared<PriceLogger>();
    auto alert = std::make_shared<PriceAlert>(90);

    market.attach(logger);
    market.attach(alert);

    simulateTrading(market);

    market.detach(logger);

    simulateTrading(market);
    return 0;
}