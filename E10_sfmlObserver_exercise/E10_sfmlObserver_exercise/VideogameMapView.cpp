#include "VideogameMapView.h"

VideogameMapView::VideogameMapView(GameCharacter *gc) : subject(gc) {
    // Create the SFML window
    window.create(sf::VideoMode(800, 799), "Game Map View");

    // Load the map image
    mapTexture.loadFromFile("./res/large_map.jpg");
    mapSprite.setTexture(mapTexture);

    // Create the player circle
    player.setRadius(10);
    player.setFillColor(sf::Color::Red);
    subject->subscribe(this);
}

VideogameMapView::~VideogameMapView() {
    window.close();
    subject->unsubscribe();
}

void VideogameMapView::update() {
    x = subject->getPosX();
    y = subject->getPosY();
    draw();
}

void VideogameMapView::attach() {
    subject->subscribe(this);
}

void VideogameMapView::detach() {
    subject->unsubscribe();
}

void VideogameMapView::draw() {
    if (window.isOpen()) {
        // Clear the window
        window.clear();

        // Draw the map
        window.draw(mapSprite);

        // Set the position of the player circle
        player.setPosition(x, y);

        // Draw the player circle
        window.draw(player);

        // Display the window
        window.display();

        std::cout << "Videogame MapView - x: " << x << " - y: " << y << std::endl;
    }

}
