#include <iostream>
#include <memory>
#include <cmath>

// ---------------------------------------------------------
// Il Target (L'interfaccia moderna che il nostro sistema si aspetta)
// ---------------------------------------------------------
class ModernPaymentSystem {
public:
    virtual ~ModernPaymentSystem() = default;
    virtual void processPayment(double amount) = 0;
};

// ---------------------------------------------------------
// L'Adaptee (La vecchia libreria incompatibile che dobbiamo usare)
// ---------------------------------------------------------
class LegacyPayPal {
public:
    // Questa funzione vuole separatamente la parte intera e i centesimi!
    void makeTransaction(int dollars, int cents) {
        std::cout << "Pagamento inviato tramite vecchio sistema PayPal: "
                  << dollars << "." << (cents < 10 ? "0" : "") << cents << " USD\n";
    }
};

// ---------------------------------------------------------
// TODO: L'Adapter
// ---------------------------------------------------------
// Crea una classe 'PayPalAdapter' che erediti pubblicamente da 'ModernPaymentSystem'.
// 1. Deve contenere un puntatore o un riferimento a 'LegacyPayPal' (passato nel costruttore).
// 2. Deve implementare il metodo 'processPayment(double amount)'.
// 3. All'interno di quel metodo, deve "spacchettare" il double in due int (es: 99.45 diventa 99 e 45)
//    e invocare il metodo 'makeTransaction' della vecchia libreria.
// Suggerimento per i centesimi: attenzione agli arrotondamenti quando converti da double a int!
// Puoi usare std::round o operazioni matematiche basilari.

class PayPalAdapter : public ModernPaymentSystem {
public:

    PayPalAdapter(std::shared_ptr<LegacyPayPal> l) : pp(std::move(l)) {}

    void processPayment(double amount) override {
        double doubleDollars;
        int cents = std::modf(amount, &doubleDollars)*100;
        int intDollars = static_cast<int>(doubleDollars);
        pp->makeTransaction(intDollars, cents);
    }

private:
    std::shared_ptr<LegacyPayPal> pp;
};


// ---------------------------------------------------------
// Il Client (Il codice del nostro e-commerce che non vogliamo cambiare)
// ---------------------------------------------------------
void runCheckout(ModernPaymentSystem& paymentGateway, double total) {
    std::cout << "Inizio transazione sul nostro e-commerce...\n";
    paymentGateway.processPayment(total);
}

// ---------------------------------------------------------
// Main di Test
// ---------------------------------------------------------
int main() {
    // La vecchia libreria che siamo obbligati a usare
    auto oldPayPal = std::make_shared<LegacyPayPal>();

    // Il nostro Adapter che fa da ponte
    std::unique_ptr<ModernPaymentSystem> adapter = std::make_unique<PayPalAdapter>(oldPayPal);

    // Il client usa l'interfaccia moderna, ma sotto il cofano gira il vecchio PayPal!
    runCheckout(*adapter, 99.45);
    runCheckout(*adapter, 10.05);
    runCheckout(*adapter, 100.00);

    return 0;
}