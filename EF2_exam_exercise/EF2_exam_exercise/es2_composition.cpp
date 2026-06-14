// Exercise 2 (10+2 points) - Composition
// An online computer shop lets customers configure custom PCs. Use class
// composition to model the relationships between the entities.
// A Computer is composed of exactly one CPU, a collection of MemoryModule
// and a collection of Drive. Computer provides: totalPrice() (components
// plus a fixed 50.00 euro assembly fee), totalMemoryGB(), printSpecs(),
// and methods to add a memory module or a drive.
// CustomerOrder contains the customer name and a collection of Computer:
// it allows adding a computer, computing the order total and printing the
// receipt (10 points).
// removeDrive(position) must throw std::out_of_range if the position is
// not valid (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class CPU {
public:
    CPU(const std::string& model, int cores, double price);
    // TODO getters, print method
private:
    std::string model;
    int cores;
    double price;
};

// TODO class MemoryModule  (size in GB, price)

// TODO class Drive         (type "SSD"/"HDD", capacity in GB, price)

class Computer {
public:
    // TODO constructor receiving the CPU
    // TODO addMemory(...), addDrive(...)
    // TODO removeDrive(int position)  -> throws std::out_of_range
    // TODO double totalPrice() const;   // components + 50.00 assembly fee
    // TODO int totalMemoryGB() const;
    // TODO void printSpecs() const;
private:
    CPU cpu;                           // composition: exactly one CPU
    std::vector<MemoryModule> memory;  // composition
    std::vector<Drive> drives;         // composition
};

class CustomerOrder {
public:
    // TODO addComputer(...), orderTotal(), printReceipt()
private:
    std::string customerName;
    std::vector<Computer> computers;
};

int main() {
    // TODO configure a computer, add it to an order and print the receipt
    return 0;
}
