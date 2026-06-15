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
        std::cout << "MODEL: " << model << "\nCORES: " << cores << "\nPRICE: " << price << std::endl;
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
        if (pos < 0 || pos > drives.size() - 1)
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

    explicit CustomerOrder(std::string n) : customerName(std::move(n)) {}

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
            std::cout << "PRICE: " << computers.at(i).totalPrice() << std::endl;
        }
        std::cout << "TOTAL: " << orderTotal() << std::endl;
    }

private:
    std::string customerName;
    std::vector<Computer> computers;
};

int main() {std::cout << "=== INIZIO TEST DI TUTTI I METODI ===" << std::endl;

    // 1. TEST METODI DELLE CLASSI COMPONENTI (Getter e print)
    CPU intelI7("Intel i7-13700K", 16, 420.00);
    MemoryModule ram8GB(8, 35.00);
    Drive ssd500GB(StorageType::SSD, 500, 60.00);
    Drive hdd1TB(StorageType::HDD, 1000, 45.00);

    std::cout << "\n[TEST GETTER COMPONENTI]:" << std::endl;
    std::cout << "CPU Modello: " << intelI7.getModel() << ", Cores: " << intelI7.getCores() << ", Prezzo: " << intelI7.getPrice() << " Euro" << std::endl;
    std::cout << "RAM Modulo Size: " << ram8GB.getSize() << " GB, Prezzo: " << ram8GB.getPrice() << " Euro" << std::endl;
    std::cout << "Drive Tipo: " << (ssd500GB.getType() == StorageType::SSD ? "SSD" : "HDD")
              << ", Capacità: " << ssd500GB.getCapacity() << " GB, Prezzo: " << ssd500GB.getPrice() << " Euro" << std::endl;

    // 2. CONFIGURAZIONE E TEST COMPUTER 1 (Fascia Alta)
    std::cout << "\n[TEST COMPUTER 1]: Configurazione iniziale..." << std::endl;
    Computer pcUfficio(intelI7);
    pcUfficio.addMemory(ram8GB); // Metodo addMemory
    pcUfficio.addMemory(ram8GB);
    pcUfficio.addDrive(ssd500GB); // Metodo addDrive
    pcUfficio.addDrive(hdd1TB);

    // Test removeDrive ed eccezione std::out_of_range
    try {
        std::cout << "Tentativo rimozione drive a indice non valido (5)..." << std::endl;
        pcUfficio.removeDrive(5);
    } catch (const std::out_of_range& e) {
        std::cerr << "-> Eccezione intercettata correttamente: " << e.what() << std::endl;
    }

    try {
        std::cout << "Rimozione drive a indice 1 (l'HDD)..." << std::endl;
        pcUfficio.removeDrive(1); // Metodo removeDrive valido
        std::cout << "-> Drive rimosso correttamente." << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "-> Errore inaspettato: " << e.what() << std::endl;
    }

    // 3. CONFIGURAZIONE E TEST COMPUTER 2 (Fascia Budget)
    std::cout << "\n[TEST COMPUTER 2]: Creazione secondo PC..." << std::endl;
    CPU amdRyzen("AMD Ryzen 5 5600X", 6, 170.00);
    MemoryModule ram16GB(16, 65.00);
    Drive ssd1TB(StorageType::SSD, 1000, 85.00);

    Computer pcGaming(amdRyzen);
    pcGaming.addMemory(ram16GB);
    pcGaming.addDrive(ssd1TB);

    // Test esplicito dei metodi di calcolo su Computer 2
    std::cout << "Metodo totalMemoryGB() su PC 2: " << pcGaming.totalMemoryGB() << " GB" << std::endl;
    std::cout << "Metodo totalPrice() su PC 2 (170 + 65 + 85 + 50 assemblaggio): " << pcGaming.totalPrice() << " Euro" << std::endl;

    std::cout << "\n[STAMPA SPECIFICHE PC 2 (Metodo printSpecs)]:" << std::endl;
    pcGaming.printSpecs();

    // 4. CREAZIONE DELL'ORDINE E TEST METODI CUSTOMERORDER
    std::cout << "\n[TEST CUSTOMER ORDER]: Aggiunta di entrambi i PC all'ordine..." << std::endl;
    CustomerOrder ordineCliente("Luigi Verdi");

    ordineCliente.addComputer(pcUfficio); // Metodo addComputer (PC 1 modificato)
    ordineCliente.addComputer(pcGaming);  // Metodo addComputer (PC 2)

    std::cout << "Metodo orderTotal() calcolato: " << ordineCliente.orderTotal() << " Euro" << std::endl;

    // Stampa finale della ricevuta complessiva
    std::cout << "\n[STAMPA RICEVUTA FINALE (Metodo printReceipt)]:" << std::endl;
    ordineCliente.printReceipt();

    return 0;
}
