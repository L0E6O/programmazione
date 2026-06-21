#include <iostream>
#include <vector>

template <typename T, int mS = 10>
class Stack {
public:
    void push(const T& n) {
        if (buffer.size()<maxSize) {
            buffer.push_back(n);
            return;
        }
        throw std::runtime_error("Stack is full!");
    }

    T pop() {
        if (!buffer.empty()) {
            T popped = buffer.back();
            buffer.pop_back();
            return popped;
        }
        throw std::runtime_error("Stack is empty!");
    }

    const T& peek() const {
        if (!buffer.empty())
            return buffer.back();
        throw std::runtime_error("Stack is empty!");
    }
private:
    std::vector<T> buffer;
    int maxSize = mS;
};

int main() {
    return 0;
}