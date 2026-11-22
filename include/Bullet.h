#pragma once

#include "GameObject.h"

class Bullet : public GameObject {
public:
    Bullet(float startX, float startY, float targetX, float targetY);

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

    float getRadius() const { return radius; }

private:
    float speed = 800.f;
    float radius = 5.f;
    float directionX = 0.f;
    float directionY = 0.f;
};