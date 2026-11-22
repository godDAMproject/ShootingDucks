#include <SFML/Graphics.hpp>
#include "GameLogic.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Duck Shooter - Test");
    window.setFramerateLimit(60);

    GameLogic game;
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                game.handleMouseMoved(static_cast<float>(pos.x),
                                      static_cast<float>(pos.y));
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i pos = sf::Mouse::getPosition(window);
                    game.handleMouseClick(static_cast<float>(pos.x),
                                          static_cast<float>(pos.y));
                }
            }
        }

        game.update(deltaTime);

        window.clear(sf::Color(135, 206, 235));
        game.draw(window);
        window.display();

        if (game.isGameOver()) {
            sf::sleep(sf::seconds(2));
            break;
        }
    }

    return 0;
}