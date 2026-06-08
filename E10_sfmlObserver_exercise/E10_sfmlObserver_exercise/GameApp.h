#ifndef OBSERVER_GAMEAPP_H
#define OBSERVER_GAMEAPP_H

#include "GameCharacter.h"
#include "VideogameMapView.h"
#include "MiniMapView.h"

// enum class game event
enum class GameEvent {
    quit, left, up, down, right, minimap, noop
};

class GameApp {
public:
    GameApp();
    bool updateGame(const GameEvent &gameEvent);
    GameEvent getEvent();

    void renderHUD();
    void draw() const {
        mainMap->draw();
        if (isMinimapOpen)
            miniMap->draw();
    }

    bool isOpen() const {
        return mainMap->isOpen();
    }

private:
    VideogameMapView* mainMap;
    MiniMapView* miniMap;
    GameCharacter* hero;
    const int STEP = 10;
    bool isMinimapOpen;

    void OpenCloseMinimap();

    bool pollEvent(sf::Event& event) {
        return mainMap->pollEvent(event);
    }
};


#endif //OBSERVER_GAMEAPP_H
