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
    CPU(std::string model, int cores, double price) : model(std::move(model)), cores(cores), price(price) {}

    std::string getModel() const{
        return model;
    }

    int getCores() const {
        return cores;
    }

    double getPrice() const {
        return price;
    }

    void print() const {
        std::cout << "MODEL: " << model << "\nCORES: " << cores << "/nPRICE: " << price << std::endl;
    }

private:
    std::string model;
    int cores;
    double price;
};

class MemoryModule {
public:
    MemoryModule(int s, double p) : size(s), price(p) {}
    int getSize() const {
        return size;
    }
    double getPrice() const {
        return price;
    }

    void print() const {
        std::cout << "SIZE: " << size << "\nPRICE: " << price << std::endl;
    }

private:
    int size; //in GB
    double price;
};

enum class StorageType {
    SSD,
    HDD
};

class Drive {
public:
    Drive(StorageType t, int c, double p) : type(t), capacity(c), price(p) {}

    StorageType getType() const {
        return type;
    }

    int getCapacity() const {
        return capacity;
    }

    double getPrice() const {
        return price;
    }

    void print() const {
        std::cout << "TYPE: " << (type == StorageType::HDD ? "HDD" : "SSD") << "\nCAPACITY: " << capacity << "\nPRICE: " << price << std::endl;
    }

private:
    StorageType type; //SSD o HDD
    int capacity; //in GB
    double price;
};

class Computer {
public:
    explicit Computer(CPU c) : cpu(std::move(c)) {}

    void addMemory(const MemoryModule& module) {
        memory.push_back(module);
    }

    void addDrive(const Drive& drive) {
        drives.push_back(drive);
    }

    void removeDrive(int pos) {
        if (pos < 0 || pos > drives.capacity() - 1)
            throw std::out_of_range("Bad index");
        drives.erase(drives.begin()+pos);
    }

    double totalPrice() const {
        double total = 0;

        total += cpu.getPrice();

        for (const auto& module : memory) {
            total+=module.getPrice();
        }

        for (const auto& drive : drives) {
            total+=drive.getPrice();
        }

        return total+50;
    }

    int totalMemoryGB() const {
        int total = 0;

        for (const auto& module : memory) {
            total+=module.getSize();
        }

        return total;
    }

    void printSpecs() const {
        std::cout << "------CPU SPECS------" << std::endl;
        cpu.print();
        std::cout << "------MEMORY SPECS------" << std::endl;
        for (int i = 0; i < memory.size(); i++) {
            std::cout << "---MODULE " << i << "---" << std::endl;
            memory.at(i).print();
        }
        std::cout << "------DRIVES SPECS------" << std::endl;
        for (int i = 0; i < drives.size(); i++) {
            std::cout << "---DRIVE " << i << "---" << std::endl;
            drives.at(i).print();
        }
    }
private:
    CPU cpu;                           // composition: exactly one CPU
    std::vector<MemoryModule> memory;  // composition
    std::vector<Drive> drives;         // composition
};

class CustomerOrder {
public:
    // TODO addComputer(...), orderTotal(), printReceipt()
    void addComputer(const Computer& newComputer) {
        computers.push_back(newComputer);
    }

    double orderTotal() const {
        double total = 0;
        for (const auto& computer : computers) {
            total += computer.totalPrice();
        }
        return total;
    }

    void printReceipt() const {
        for (int i = 0; i < computers.size(); i++) {
            std::cout << "---COMPUTER " << i << "---" << std::endl;
            std::cout << "PRICE: " << computers.at(i).totalPrice();
        }
        std::cout << "TOTAL: " << orderTotal() << std::endl;
    }

private:
    std::string customerName;
    std::vector<Computer> computers;
};

int main() {
    // TODO configure a computer, add it to an order and print the receipt
    return 0;
}
