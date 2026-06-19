#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

// ---------------------------------------------------------
// TODO 1: L'interfaccia Observer (ABC)
// ---------------------------------------------------------
// Definisci la classe base astratta 'Observer'.
// Deve avere solo un metodo virtuale puro 'update' che accetta
// il titolo del video (stringa) e non restituisce nulla.

// -> SCRIVI QUI L'INTERFACCIA Observer <-
class Observer {
public:
    virtual void update(const std::string& s) = 0;
};

// ---------------------------------------------------------
// Il Subject: Il Canale YouTube
// ---------------------------------------------------------
class YouTubeChannel {
private:
    std::string channelName;

    // TODO 2: La collezione di osservatori
    // Scegli lo smart pointer corretto per memorizzare gli osservatori.
    // Ricorda: il canale NON deve possedere gli utenti, deve solo "osservarli".
    std::vector<std::weak_ptr<Observer>> observers;

public:
    YouTubeChannel(std::string name) : channelName(name) {}

    // TODO 3: Registrazione (Attach)
    // Implementa il metodo per aggiungere un osservatore alla lista.
    // Pensa a quale tipo di smart pointer deve accettare in ingresso.
    void attach(const std::shared_ptr<Observer>& ob) {
        observers.push_back(ob);
    }

    // TODO 4: Notifica (Notify)
    // Implementa 'notifyObservers(const std::string& videoTitle)'.
    // Deve scorrere la lista degli osservatori.
    // ATTENZIONE: prima di notificare, devi controllare se l'osservatore
    // esiste ancora in memoria (non è scaduto). Se è scaduto, dovresti rimuoverlo.
    void notifyObservers(const std::string& videoTitle) {
        for (int i = 0; i < observers.size();) {
            if (auto ob = observers[i].lock()) {
                ob->update(videoTitle);
                i++;
            } else {
                observers.erase(observers.begin() + i);
            }
        }
    }

    void publishVideo(const std::string& title) {
        std::cout << "\n[" << channelName << "] Ha pubblicato un nuovo video: " << title << "\n";
        notifyObservers(title);
    }
};

// ---------------------------------------------------------
// TODO 5: L'Osservatore Concreto (L'Iscritto)
// ---------------------------------------------------------
// Crea la classe 'Subscriber' che eredita da 'Observer'.
// Deve avere un membro privato 'std::string userName' inizializzato dal costruttore.
// Implementa il metodo 'update' in modo che stampi:
// "[NomeUtente] ha ricevuto la notifica per il video: [TitoloVideo]"

// -> SCRIVI QUI LA CLASSE Subscriber <-
class Subscriber : public Observer{
public:
    Subscriber(std::string n) : userName(std::move(n)) {}

    void update(const std::string& s) {
        std::cout << userName << " ha ricevuto la notifica per il video: " << s << std::endl;
    }
private:
    std::string userName;
};


// ---------------------------------------------------------
// Main di Test
// ---------------------------------------------------------
int main() {
    YouTubeChannel channel("C++ Masterclass");

    // Creiamo il primo iscritto (vive per tutto il main)
    auto sub1 = std::make_shared<Subscriber>("Alice");
    channel.attach(sub1);

    // Creiamo uno scope ristretto per il secondo iscritto
    {
        auto sub2 = std::make_shared<Subscriber>("Bob");
        channel.attach(sub2);

        // Primo video: entrambi sono vivi, entrambi ricevono la notifica
        channel.publishVideo("Intro agli Smart Pointers");

        // Qui sub2 (Bob) esce dallo scope e viene distrutto automaticamente
    }

    // Secondo video: Bob non esiste più, solo Alice deve ricevere la notifica
    channel.publishVideo("I segreti dell'Observer Pattern");

    return 0;
}