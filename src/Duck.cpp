#include "Duck.h"
#include <cmath>
#include <cstdlib>

Duck::Duck(float startX, float startY, float speed)
    : speed(speed) {
    x = startX;
    y = startY;
}

void Duck::update(float deltaTime) {
    // Движение вправо + колебание по Y (имитация полёта)
    x += speed * deltaTime;
    y += std::sin(x * 0.02f) * 0.5f;

    // Если утка улетела за экран — она "мертва"
    if (x > 850.f) {
        alive = false;
    }
}

void Duck::draw(sf::RenderWindow& window) const {
    if (!alive) return;

    // Рисуем утку как цветной круг
    sf::CircleShape shape(size / 2.f);
    shape.setFillColor(getColor());
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
    shape.setPosition(x - size / 2.f, y - size / 2.f);
    window.draw(shape);
}

bool Duck::collidesWith(float bulletX, float bulletY, float bulletRadius) const {
    float dx = x - bulletX;
    float dy = y - bulletY;
    float distance = std::sqrt(dx * dx + dy * dy);
    return distance < (size / 2.f + bulletRadius);
}

sf::FloatRect Duck::getBounds() const {
    return sf::FloatRect(x - size / 2.f, y - size / 2.f, size, size);
}

// Золотая утка
GoldenDuck::GoldenDuck(float startX, float startY, float speed)
    : Duck(startX, startY, speed) {
    size = 35.f;
}

// Утка-бомба
BombDuck::BombDuck(float startX, float startY, float speed)
    : Duck(startX, startY, speed) {
    size = 45.f;
}