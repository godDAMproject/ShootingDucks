#include "Bullet.h"
#include <cmath>

Bullet::Bullet(float startX, float startY, float targetX, float targetY) {
    x = startX;
    y = startY;

    // Вычисляем направление
    float dx = targetX - startX;
    float dy = targetY - startY;
    float length = std::sqrt(dx * dx + dy * dy);

    if (length > 0.f) {
        directionX = dx / length;
        directionY = dy / length;
    }
}

void Bullet::update(float deltaTime) {
    x += directionX * speed * deltaTime;
    y += directionY * speed * deltaTime;

    // Пуля "умирает", если вылетела за экран
    if (x < -50.f || x > 850.f || y < -50.f || y > 650.f) {
        alive = false;
    }
}

void Bullet::draw(sf::RenderWindow& window) const {
    if (!alive) return;

    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(x - radius, y - radius);
    window.draw(shape);
}