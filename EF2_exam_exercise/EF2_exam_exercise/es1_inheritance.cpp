// Exercise 1 (10 points) - Inheritance
// A music streaming service offers three subscription plans. Every
// subscription is associated with an account name. Monthly revenue:
// - Free:    0 euro, but the service earns 0.02 euro for every ad shown
//            to the subscriber during the month
// - Premium: 10.99 euro plus 4.00 euro for every screen beyond the first
// - Student: half the base price of a Premium subscription (no extra screens)
// Implement a base class Subscription with functions to print the
// subscription data and compute the monthly revenue, using inheritance.
// Implement a global function calcTotalRevenue() that, given a vector with
// all the active subscriptions, returns the total monthly revenue.

#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Subscription {
public:
    Subscription(std::string name) : account(std::move(name)){}

    virtual ~Subscription() = default;

    virtual void printSubData() = 0;

    virtual double monthlyRevenue() = 0;
protected:
    std::string account;
};

class FreeSubscription : public Subscription {
public:
    explicit FreeSubscription (std::string name) : Subscription(std::move(name)) {}

    void printSubData() override {
        std::cout << "FREE SUBSCRIPTION:\nNAME: " << account << "\nADS SHOWN: " << adsShown << std::endl;
    }

    double monthlyRevenue() override {
        return 0.02*adsShown;
    }
private:
    int adsShown = 100;
};

class PremiumSubscription : public Subscription {
public:
    explicit PremiumSubscription(std::string name, int screenNumber=1) : Subscription(std::move(name)), screenNumber(screenNumber){}

    void printSubData() override {
        std::cout << "PREMIUM SUBSCRIPTION:\nNAME: " << account << "\nSCREEN NUMBER: " << screenNumber << std::endl;
    }

    double monthlyRevenue() override {
        return BASE_FEE + 4*(screenNumber-1);
    }

private:
    int screenNumber;
    const double BASE_FEE = 10.99;
};

class StudentSubscription : public Subscription {
public:
    explicit StudentSubscription(std::string name) : Subscription(std::move(name)){}

    void printSubData() override {
        std::cout << "STUDENT SUBSCRIPTION:\nNAME: " << account << std::endl;
    }

    double monthlyRevenue() override {
        return BASE_FEE;
    }
private:
    const float BASE_FEE = 5.5;
};

double calcTotalRevenue(const std::vector<Subscription*>& subs) {
    double totalRevenue = 0;
    for(const auto sub:subs) {
        totalRevenue += sub->monthlyRevenue();
    }
    return totalRevenue;
}

int main() {
    std::vector<Subscription*> subs;

    auto f = new FreeSubscription("Luca");
    subs.push_back(f);
    auto p = new PremiumSubscription("Leonardo", 1);
    subs.push_back(p);
    auto s = new StudentSubscription("Bruno");
    subs.push_back(s);

    std::cout << "subs data:" << std::endl;
    for (const auto sub : subs) {
        sub->printSubData();
    }

    std::cout << "Total monthly revenue: " << calcTotalRevenue(subs) << std::endl;

    for (const auto sub : subs) {
        delete sub;
    }

    return 0;
}
