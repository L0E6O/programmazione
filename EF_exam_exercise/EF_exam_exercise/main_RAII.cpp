#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>

class HardwareDevice {
public:
    HardwareDevice(int intr = 0) : interrupt(intr) {}

    void lowLevelOp() throw(std::runtime_error) {
        if (!interrupt) {
            throw std::runtime_error("Interrupt is equal to 0");
        }
        std::cout << "Low level op successfull" << std::endl;
    }
    // other methods...
private:
    int interrupt;
};

class DeviceManager {
public:
    DeviceManager(int interrupt) : dvc(new HardwareDevice(interrupt)) {}

    ~DeviceManager() {
        delete dvc;
    }

    void use() { // ... something
        dvc->lowLevelOp();
    }
    // other methods...
private:
    HardwareDevice* const dvc;
};

class DeviceManagerRAII {
public:
    DeviceManagerRAII(int interrupt) : hd(new HardwareDevice(interrupt)) {}

    void use() {
        hd->lowLevelOp();
    }

private:
    std::unique_ptr<HardwareDevice> const hd = std::make_unique<HardwareDevice>();
};

void test(int interrupt) {
    DeviceManager* mgr = new DeviceManager(interrupt);

    try {
        mgr->use();
    } catch (std::runtime_error e) {
        delete mgr;
        throw std::runtime_error(e.what());
    }

    delete mgr;
}

void testNotRaw(int interrupt) {
    auto mgr = std::make_unique<DeviceManagerRAII>(interrupt);

    mgr->use(); //throws std::runtime_error
}

int main() {
    test(3);
    test(0); // will throw
    testNotRaw(2);
}