#include "MiniMapView.h"

MiniMapView::MiniMapView(GameCharacter *gc) : visible(true) {
    // Create the SFML window
    window.create(sf::VideoMode(400, 400), "Minimap View");

    // Load the map image
    mapTexture.loadFromFile("./res/mini_map.jpg");
    mapSprite.setTexture(mapTexture);

    // Create the player circle
    player.setRadius(10);
    player.setFillColor(sf::Color::Red);
    subject->subscribe(this);
}

MiniMapView::~MiniMapView() {
    window.close();
    subject->unsubscribe();
}

void MiniMapView::update() {
    x = subject->getPosX();
    y = subject->getPosY();
    draw();
}

void MiniMapView::attach() {
    subject->subscribe(this);
}

void MiniMapView::detach() {
    subject->unsubscribe();
}

void MiniMapView::draw() {
    if (window.isOpen() && visible) {
        // Clear the window
        window.clear();

        // Draw the map
        window.draw(mapSprite);

        // Set the position of the player circle
        player.setPosition(x / 4 + 180, y / 4);

        // Draw the player circle
        window.draw(player);

        // Display the window
        window.display();

        std::cout << "Mini map - x: " << x << " - y: " << y << std::endl;
    }
}
