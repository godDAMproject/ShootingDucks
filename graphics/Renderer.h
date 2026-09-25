#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Renderer {
public:
    Renderer(sf::RenderWindow& window);

    void clear(sf::Color color = sf::Color(135, 206, 235));
    void display();

    void drawText(const std::string& str, float x, float y, unsigned int size, sf::Color color = sf::Color::White);
    void drawSprite(const sf::Sprite& sprite);
    void drawTexture(const sf::Texture& texture, float x, float y);
    void drawBackground(const std::string& textureName);
    void drawCrosshair(float x, float y);
    void drawRect(float x, float y, float width, float height, sf::Color color);

    // Управление камерой (View)
    void setView(const sf::View& view);
    sf::View getView() const;

private:
    sf::RenderWindow& m_window;
};
