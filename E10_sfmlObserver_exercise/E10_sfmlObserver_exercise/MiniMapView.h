#ifndef OBSERVER_MINIGUIMAP_H
#define OBSERVER_MINIGUIMAP_H

#include "Observer.h"
#include "Display.h"
#include <iostream>
#include "GameCharacter.h"
#include "SFML/Graphics.hpp"

class MiniMapView : public Display, public Observer {
public:
    explicit MiniMapView(GameCharacter *gc);
    virtual ~MiniMapView();

    // Display
    void draw() override;

    void update() override;
    void attach() override;
    void detach() override;

private:
    int x, y;
    bool visible;
    GameCharacter *subject;

    sf::RenderWindow window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::CircleShape player;
};

#endif //OBSERVER_MINIGUIMAP_H
