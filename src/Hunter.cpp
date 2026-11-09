#include "Hunter.h"

Hunter::Hunter() {
    x = 400.f;  // центр экрана
    y = 300.f;
}

void Hunter::update(float deltaTime) {
    // Плавное следование за мышью (интерполяция)
}

void Hunter::draw(sf::RenderWindow& window) const {
    // Рисуем прицел как перекрестие
    sf::CircleShape outer(size / 2.f);
    outer.setFillColor(sf::Color::Transparent);
    outer.setOutlineColor(sf::Color::Red);
    outer.setOutlineThickness(2.f);
    outer.setPosition(x - size / 2.f, y - size / 2.f);
    window.draw(outer);

    // Центральная точка
    sf::CircleShape center(3.f);
    center.setFillColor(sf::Color::Red);
    center.setPosition(x - 3.f, y - 3.f);
    window.draw(center);
}

void Hunter::setMousePosition(float mouseX, float mouseY) {
    // Плавное движение: прицел догоняет мышь
    x += (mouseX - x) * 0.3f;
    y += (mouseY - y) * 0.3f;
}

Bullet Hunter::shoot(float targetX, float targetY) const {
    return Bullet(x, y, targetX, targetY);
}