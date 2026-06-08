#include "GameApp.h"

// render Head Up Display
void GameApp::renderHUD() {
    std::cout << "Press: w,a,s,d (to move), m (show/close minimap) or Q to quit." << std::endl;
}

GameApp::GameApp() {
    hero = new GameCharacter;

    mainMap = new VideogameMapView( hero );
    miniMap = new MiniMapView( hero );
    isMinimapOpen = true;
    // TODO refresh all views... it0's up to GameCharacters
}

// poll event from keyboard
GameEvent GameApp::getEvent() {
    sf::Event event;
    bool keyPressed = false; // Flag to track key state

    while (pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return GameEvent::quit;
        else if (event.type == sf::Event::KeyPressed && !keyPressed) {
            keyPressed = true;
            renderHUD();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                return GameEvent::quit;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                return GameEvent::up;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                return GameEvent::left;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                return GameEvent::down;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                return GameEvent::right;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                return GameEvent::minimap;
        } else
            return GameEvent::noop;
    }
    return GameEvent::noop;
}

void GameApp::OpenCloseMinimap() {
    if (isMinimapOpen) {
        delete miniMap;
        isMinimapOpen = false;
    } else {
        miniMap = new MiniMapView(hero);
        isMinimapOpen = true;
        hero->notify();
    }
}

// update game status depending on player's action
bool GameApp::updateGame(const GameEvent &gameEvent) {
    switch (gameEvent) {
        case GameEvent::quit: //
            return true;
        case GameEvent::up: {
            // graphics coordinates: (0,0) is top-left
            hero->move(0, -STEP);
            break;
        }
        case GameEvent::left: {
            hero->move(-STEP, 0);
            break;
        }
        case GameEvent::down: {
            // graphics coordinates: (0,0) is top-left
            hero->move(0, STEP);
            break;
        }
        case GameEvent::right: {
            hero->move(STEP, 0);
            break;
        }
        case GameEvent::minimap: {
            OpenCloseMinimap();
            break;
        }
        case GameEvent::noop: {
            //renderHUD();
            break;
        }
    }
    return false;
}
