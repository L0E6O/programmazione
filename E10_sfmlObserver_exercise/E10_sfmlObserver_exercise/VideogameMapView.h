#ifndef OBSERVER_GUIMAP_H
#define OBSERVER_GUIMAP_H

#include "Observer.h"
#include "Display.h"
#include "GameCharacter.h"
#include <iostream>
#include "SFML/Graphics.hpp"

class VideogameMapView : public Display, public Observer {
public:
    explicit VideogameMapView(GameCharacter *gc);
    virtual ~VideogameMapView();

    // Display
    void draw() override;

    void update() override;
    void attach() override;
    void detach() override;


    bool isOpen() const {
        return window.isOpen();
    }
    bool pollEvent(sf::Event &event) {
        return window.pollEvent(event);
    }

private:
    int x, y;
    GameCharacter *subject;

    sf::RenderWindow window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::CircleShape player;
};

#endif //OBSERVER_GUIMAP_H
