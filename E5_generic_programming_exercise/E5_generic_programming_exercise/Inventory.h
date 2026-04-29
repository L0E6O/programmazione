#ifndef INVENTORY_H
#define INVENTORY_H

template<typename T, int N=5>
class Inventory {
public:
    explicit Inventory() {
        for (bool element:usedElements) {
            element = false;
        }
    }
    virtual ~Inventory() = default;
    bool setElement(int n, const T& newObj);
    bool getElement(int n, T& obj);
    int getMaxElements() const{
        return maxElements;
    }
    virtual void printContent() const;

protected:
    int maxElements=N; // max number of objects that can be stored
    T elements[N];
    bool usedElements[N];
};

template<typename T, int N>
void Inventory<T, N>::printContent() const {
    for (int i=0; i<N; i++) {
        if (usedElements[i])
            std::cout << i << ":" << elements[i] << std::endl;
    }
}

template<typename T, int N>
bool Inventory<T, N>::setElement(int n, const T& newObj) {
    if (n<maxElements && n>=0 && usedElements[n]==false) {
        elements[n] = newObj;
        usedElements[n] = true;
        return true;
    }
    return false;
}

template <typename T, int N>
bool Inventory<T, N>::getElement(int n, T& obj) {
    if (n<=0 && n<maxElements && usedElements[n]) {
        obj = elements[n];
        usedElements[n] = false;
        return true;
    }
    return false;
}

#endif //INVENTORY_H