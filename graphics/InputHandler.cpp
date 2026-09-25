#include "InputHandler.h"

InputHandler::InputHandler(sf::RenderWindow& window) : m_window(window) {}

sf::Vector2f InputHandler::getMousePosition() const {
    sf::Vector2i pixelPos = sf::Mouse::getPosition(m_window);
    return m_window.mapPixelToCoords(pixelPos);
}

bool InputHandler::isLeftMouseClicked(const sf::Event& event) const {
    return event.type == sf::Event::MouseButtonPressed &&
           event.mouseButton.button == sf::Mouse::Left;
}

bool InputHandler::isRightMouseClicked(const sf::Event& event) const {
    return event.type == sf::Event::MouseButtonPressed &&
           event.mouseButton.button == sf::Mouse::Right;
}

bool InputHandler::isKeyPressed(const sf::Event& event, sf::Keyboard::Key key) const {
    return event.type == sf::Event::KeyPressed &&
           event.key.code == key;
}

bool InputHandler::isMouseOver(const sf::FloatRect& bounds) const {
    return bounds.contains(getMousePosition());
}

bool InputHandler::isMouseDown(sf::Mouse::Button button) const {
    return sf::Mouse::isButtonPressed(button);
}

bool InputHandler::isKeyDown(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}
