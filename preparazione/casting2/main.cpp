#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ---------------------------------------------------------
// Classe Base Astratta
// ---------------------------------------------------------
class MediaItem {
protected:
    std::string title;
public:
    MediaItem(std::string t) : title(std::move(t)) {}
    virtual ~MediaItem() = default;

    virtual void play() const = 0;
    std::string getTitle() const { return title; }
};

// ---------------------------------------------------------
// Classi Derivate
// ---------------------------------------------------------
class Audio : public MediaItem {
public:
    Audio(std::string t) : MediaItem(std::move(t)) {}

    void play() const override {
        std::cout << "Riproduzione traccia audio: " << getTitle() << "\n";
    }

    // Metodo esclusivo di Audio
    void boostBass() {
        std::cout << "  [Effetto] Bassi potenziati per questo brano!\n";
    }
};

class Video : public MediaItem {
public:
    Video(std::string t) : MediaItem(t) {}

    void play() const override {
        std::cout << "Riproduzione filmato video: " << getTitle() << "\n";
    }

    // Metodo esclusivo di Video
    void enableSubtitles() {
        std::cout << "  [Opzione] Sottotitoli attivati per non fare rumore.\n";
    }
};

// ---------------------------------------------------------
// Il Gestore della Playlist
// ---------------------------------------------------------
class Playlist {
private:
    // TODO 1: Crea un vettore STL che contenga puntatori unici (std::unique_ptr) a MediaItem.
    std::vector<std::unique_ptr<MediaItem>> items;

public:
    // TODO 2: Implementa 'addMedia'. Deve accettare il puntatore unico e inserirlo nel vettore.
    void addMedia(std::unique_ptr<MediaItem> n) {
        items.push_back(std::move(n));
    }

    // TODO 3: Implementa 'processPlaylist'.
    // Deve scorrere tutti gli elementi della playlist ed eseguire:
    // 1. Il metodo polimorfico 'play()' (valido per tutti).
    // 2. Un controllo sul tipo reale:
    //    - SE l'elemento è un Audio, esegui anche 'boostBass()'.
    //    - SE l'elemento è un Video, esegui anche 'enableSubtitles()'.
    // Suggerimento: usa il cast di C++ che restituisce nullptr se il tipo non coincide.
    void processPlaylist() {
        for (const auto& item : items) {
            item->play();
            if (auto* audio = dynamic_cast<Audio*>(item.get())) {
                audio->boostBass();
            } else if (auto* video = dynamic_cast<Video*>(item.get())) {
                video->enableSubtitles();
            }
        }
    }
};

// ---------------------------------------------------------
// Main di Test
// ---------------------------------------------------------
int main() {
    Playlist myPlaylist;

    // TODO 4: Popola la playlist.
    std::unique_ptr<MediaItem> audio = std::make_unique<Audio>("In the end");
    std::unique_ptr<MediaItem> video = std::make_unique<Video>("Inception Trailer");

    myPlaylist.addMedia(std::move(audio));
    myPlaylist.addMedia(std::move(video));

    std::cout << "--- Avvio Riproduzione Playlist ---\n";
    myPlaylist.processPlaylist();

    return 0;
}