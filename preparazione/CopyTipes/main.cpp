// Exercise - Deep vs Shallow Copy (10+2+2 points)
// The class DynamicArray wraps a raw array allocated on the heap.
// The function processArray() (which cannot be modified) takes a DynamicArray
// by value, modifies it, and returns it.
//
// The default compiler-generated copy constructor does a shallow copy,
// causing two objects to share the same underlying array — leading to
// double-free and unexpected modifications.
//
// Implement a correct deep copy constructor and copy assignment operator
// for DynamicArray (10 points).
// Implement the move constructor and move assignment operator to avoid
// unnecessary copies (2 points).
// Explain in a comment why the destructor, copy constructor, and copy
// assignment operator must always be implemented together (2 points).

//the rule of three exists because first: if we want to make making a copy available, we need to be able to do it via constructor or via =
//then, most importantly, if there's the need to specify how to copy a certain object, then probably the object needs a special treatment even for the destruction (to prevent memory leaks as in this file)

#include <iostream>
#include <stdexcept>

class DynamicArray {
public:
    explicit DynamicArray(int size) : size(size), data(new int[size]{}) {}
    ~DynamicArray() { delete[] data; }

    // TODO implement deep copy constructor
    DynamicArray(const DynamicArray& other) : size(other.getSize()), data(new int[other.size]{}) {
        for (int i = 0; i < other.getSize(); i++) {
            data[i] = other.get(i);
        }
    }
    // TODO implement copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            data = new int[other.getSize()]{};
            for (int i = 0; i < other.getSize(); i++) {
                data[i] = other.get(i);
            }
        }
        return *this;
    }

    void set(int index, int value) { data[index] = value; }
    int get(int index) const { return data[index]; }
    int getSize() const { return size; }

private:
    int size;
    int* data;
};

// DO NOT MODIFY
void printArray(const DynamicArray& arr) {
    for (int i = 0; i < arr.getSize(); i++)
        std::cout << arr.get(i) << " ";
    std::cout << std::endl;
}

// DO NOT MODIFY
DynamicArray processArray(DynamicArray arr) {  // passed by value intentionally
    for (int i = 0; i < arr.getSize(); i++)
        arr.set(i, arr.get(i) * 2);
    return arr;
}

int main() {
    DynamicArray a(5);
    for (int i = 0; i < 5; i++) a.set(i, i + 1);

    // TODO call processArray, print before and after
    // show that the original array is not modified
    return 0;
}