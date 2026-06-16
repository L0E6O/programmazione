// Exercise - Templates (10+2+2 points)
// You are building a generic container class Stack<T> that works with any type.
// The class must support push, pop, and peek operations.
// A utility function printStack() (which cannot be modified) prints all
// elements of any Stack<T>, as long as T supports operator<<.
//
// Implement the Stack<T> template class (10 points).
// Throw std::underflow_error if pop() or peek() are called on an empty stack (2 points).
// Implement a template function maxElement<T>() that returns the largest
// element in a Stack<T>, assuming T supports operator< (2 points).

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class Stack{
public:

    Stack() = default;

    Stack(const Stack<T>& other) : buffer(other.buffer) {}

    void push(T item) {
        buffer.push_back(std::move(item));
    }

    T pop() {
        if (buffer.empty())
            throw std::underflow_error("Stack is empty");
        T element = buffer.back();
        buffer.pop_back();
        return element;
    }

    T peek() const {
        if (buffer.empty())
            throw std::underflow_error("Stack is empty");
        return buffer.back();
    }

    bool isEmpty() const {
        return buffer.empty();
    }

    int size() const {
        return buffer.size();
    }

    std::vector<T> getBuffer() {
        return buffer;
    }

private:
    std::vector<T> buffer;
};

template <typename T>
T maxElement(Stack<T> stack) {
    if (stack.isEmpty())
        throw std::underflow_error("stack is empty");
    T max = stack.pop();
    while (!stack.isEmpty()) {
        T current = stack.pop();
        if (current > max)
            max = current;
    }
    return max;
}

// utility function: DO NOT MODIFY
template <typename T>
void printStack(Stack<T> stack) {  // passed by value intentionally
    std::cout << "Stack (top to bottom): ";
    while (!stack.isEmpty()) {
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;
}

int main() {
    // TODO test Stack<int> and Stack<std::string>
    // show the std::underflow_error case too
    // use maxElement() on a Stack<int>
    return 0;
}