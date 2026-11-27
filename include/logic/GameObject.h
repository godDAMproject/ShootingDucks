#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;

    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;

    float getX() const { return x; }
    float getY() const { return y; }
    bool isAlive() const { return alive; }

    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

protected:
    float x = 0.f;
    float y = 0.f;
    bool alive = true;
};

