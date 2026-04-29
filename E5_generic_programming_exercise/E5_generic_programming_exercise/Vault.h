#ifndef VAULT_H
#define VAULT_H

#include <iostream>
#include "Inventory.h"

template <typename T, int N=10>
class Vault : public Inventory<T, N> {
public:
    Vault(int x, int y) : x(x), y(y), closed(false) {}
    virtual ~Vault() = default;

    void printContent() const override;
    void open() {
        closed = false;
    }

    int getPosX() const {
        return x;
    }
    int getPosY() const {
        return y;
    }

protected:
    int x, y;
    bool closed;
};

template<typename T, int N>
void Vault<T, N>::printContent() const {
    if (!closed) {
        std::cout << "The vault contains:" << std::endl;
        Inventory<T, N>::printContent();
    }
}

#endif //VAULT_H
