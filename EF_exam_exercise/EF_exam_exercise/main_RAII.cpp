#include <stdexcept>

class HardwareDevice {
public:
    HardwareDevice(int intr = 0) : interrupt(intr) {}

    void lowLevelOp() throw(std::runtime_error) { // ... something
        if (!interrupt) {
            // FIXME launch exception
        }
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

void test(int interrupt) {
    DeviceManager* mgr = new DeviceManager(interrupt);
    // XXX it may throw an exception
    mgr->use();
    // ...
    delete mgr;
}

int main() {
    test(3);
    test(0); // will throw
}