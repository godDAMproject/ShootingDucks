#include "Renderer.h"
#include "AssetManager.h"

Renderer::Renderer(sf::RenderWindow& window) : m_window(window) {}

void Renderer::clear(sf::Color color) {
    m_window.clear(color);
}

void Renderer::display() {
    m_window.display();
}

void Renderer::drawText(const std::string& str, float x, float y, unsigned int size, sf::Color color) {
    sf::Text text;
    text.setFont(AssetManager::instance().getFont("default"));
    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(x, y);
    m_window.draw(text);
}

void Renderer::drawSprite(const sf::Sprite& sprite) {
    m_window.draw(sprite);
}

void Renderer::drawTexture(const sf::Texture& texture, float x, float y) {
    sf::Sprite sprite(texture);
    sprite.setPosition(x, y);
    m_window.draw(sprite);
}

void Renderer::drawBackground(const std::string& textureName) {
    if (!AssetManager::instance().hasTexture(textureName)) {
        return;
    }
    const sf::Texture& tex = AssetManager::instance().getTexture(textureName);
    sf::Sprite bg(tex);
    sf::Vector2u winSize = m_window.getSize();
    sf::Vector2u texSize = tex.getSize();
    if (texSize.x > 0 && texSize.y > 0) {
        bg.setScale(
            static_cast<float>(winSize.x) / texSize.x,
            static_cast<float>(winSize.y) / texSize.y
        );
    }
    m_window.draw(bg);
}

void Renderer::drawCrosshair(float x, float y) {
    if (AssetManager::instance().hasTexture("crosshair")) {
        const sf::Texture& tex = AssetManager::instance().getTexture("crosshair");
        sf::Sprite sprite(tex);
        sf::Vector2u size = tex.getSize();
        sprite.setOrigin(size.x / 2.f, size.y / 2.f);
        sprite.setPosition(x, y);
        m_window.draw(sprite);
        return;
    }

    sf::CircleShape outer(15.f);
    outer.setOrigin(15.f, 15.f);
    outer.setPosition(x, y);
    outer.setFillColor(sf::Color::Transparent);
    outer.setOutlineThickness(2.f);
    outer.setOutlineColor(sf::Color::Red);

    sf::CircleShape center(2.f);
    center.setOrigin(2.f, 2.f);
    center.setPosition(x, y);
    center.setFillColor(sf::Color::Red);

    m_window.draw(outer);
    m_window.draw(center);
}

void Renderer::drawRect(float x, float y, float width, float height, sf::Color color) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(x, y);
    rect.setFillColor(color);
    m_window.draw(rect);
}

void Renderer::setView(const sf::View& view) {
    m_window.setView(view);
}

sf::View Renderer::getView() const {
    return m_window.getView();
}
