#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

// Classe di supporto, GIA' COMPLETA: serve solo per testare
// i template con un tipo "non primitivo" (non devi modificarla,
// ma guarda come implementa operator> e operator<< perche'
// sono proprio i requisiti che i tuoi template si aspettano
// da un tipo generico T).
class Persona {
private:
    std::string nome;
    int eta;

public:
    Persona(std::string nome = "", int eta = 0) : nome(nome), eta(eta) {}

    int getEta() const { return eta; }
    std::string getNome() const { return nome; }

    // Necessario perche' trovaMassimo<Persona> possa confrontare due persone
    bool operator>(const Persona& altra) const {
        return eta > altra.eta;
    }

    // Necessario per stampare una Pila<Persona> con operator<<
    friend std::ostream& operator<<(std::ostream& os, const Persona& p) {
        os << p.nome << "(" << p.eta << ")";
        return os;
    }
};

#endif
