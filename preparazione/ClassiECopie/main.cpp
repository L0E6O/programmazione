#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ---------------------------------------------------------
// TODO 1: La classe Base Astratta (ABC)
// ---------------------------------------------------------
// Crea una classe 'Shape'.
// Deve avere:
// 1. Un distruttore virtuale (best practice!).
// 2. Un metodo puro virtuale 'print()' const.
// 3. Un metodo puro virtuale per supportare la copia polimorfica (spesso chiamato 'clone').
//    Suggerimento: deve restituire un unique_ptr a Shape.

class Shape {
public:
    virtual ~Shape() = default;
    virtual void print() const = 0;
    virtual std::unique_ptr<Shape> clone() const = 0;
};

// ---------------------------------------------------------
// TODO 2: Classi Concrete
// ---------------------------------------------------------
// Implementa due classi: 'Circle' e 'Rectangle' che ereditano da Shape.
// Devono implementare correttamente i metodi dell'ABC.
// - Circle ha un membro 'double radius'.
// - Rectangle ha due membri 'double width' e 'double height'.

class Circle : public Shape {
public:
    Circle(const double r) : radius(r) {}

    void print() const override {
        std::cout << "Radius: " << radius << std::endl;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Circle>(this->radius);
    }
private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(const double w, const double h) : width(w), height(h) {}

    void print() const override {
        std::cout << "Width: " << width << "\nHeight: " << height << std::endl;
    }

    std::unique_ptr<Shape> clone() const override {
        return std::make_unique<Rectangle>(this->width, this->height);
    }


private:
    double width;
    double height;
};


// ---------------------------------------------------------
// TODO 3: La classe Document (Gestore)
// ---------------------------------------------------------
class Document {
private:
    std::vector<std::unique_ptr<Shape>> shapes;

public:
    Document() = default;

    void addShape(std::unique_ptr<Shape> s) {
        shapes.push_back(std::move(s));
    }

    void show() const {
        for (const auto& s : shapes) {
            s->print();
        }
    }

    // TODO 4: Il Copy Constructor (La vera sfida)
    // Se provi a copiare un 'Document' ora, il compilatore si arrabbia
    // perché gli unique_ptr non sono copiabili.
    // Implementa il costruttore di copia per eseguire una DEEP COPY
    // di tutte le forme presenti in 'other', sfruttando il polimorfismo!

    Document(const Document& other) {
        for (const auto& s:other.shapes) {
            shapes.push_back(s->clone());
        }
    }

};


// ---------------------------------------------------------
// Main di Test (Non modificare)
// ---------------------------------------------------------
int main() {
    Document originalDoc;
    originalDoc.addShape(std::make_unique<Circle>(5.0));
    originalDoc.addShape(std::make_unique<Rectangle>(4.0, 3.0));

    std::cout << "--- Documento Originale ---\n";
    originalDoc.show();

    // Testiamo la Deep Copy
    Document copiedDoc = originalDoc;

    // Aggiungiamo una forma solo alla copia per dimostrare che sono indipendenti
    copiedDoc.addShape(std::make_unique<Circle>(10.0));

    std::cout << "\n--- Documento Copiato ---\n";
    copiedDoc.show();

    std::cout << "\n--- Documento Originale (dopo modifica della copia) ---\n";
    originalDoc.show();

    return 0;
}