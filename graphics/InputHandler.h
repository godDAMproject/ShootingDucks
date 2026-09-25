#pragma once
#include <SFML/Graphics.hpp>

class InputHandler {
public:
    InputHandler(sf::RenderWindow& window);

    sf::Vector2f getMousePosition() const;
    
    // Событийный ввод (Event-based)
    bool isLeftMouseClicked(const sf::Event& event) const;
    bool isRightMouseClicked(const sf::Event& event) const;
    bool isKeyPressed(const sf::Event& event, sf::Keyboard::Key key) const;
    bool isMouseOver(const sf::FloatRect& bounds) const;

    // Непрерывный ввод в реальном времени (Polling-based)
    bool isMouseDown(sf::Mouse::Button button) const;
    bool isKeyDown(sf::Keyboard::Key key) const;

private:
    sf::RenderWindow& m_window;
};
