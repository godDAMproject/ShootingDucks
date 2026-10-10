#pragma once

#include <SFML/Graphics.hpp>

// АБСТРАКЦИЯ: описывает общее поведение всех объектов в игре.
// Нельзя создать объект GameObject напрямую — только через наследников.
class GameObject {
public:
    virtual ~GameObject() = default;

    // Чисто виртуальные функции — каждый наследник ОБЯЗАН их реализовать
    virtual void update(float deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;

    // Геттеры (инкапсуляция — поля protected, доступ через методы)
    float getX() const { return x; }
    float getY() const { return y; }
    bool isAlive() const { return alive; }

    // Сеттер для позиции
    void setPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

protected:
    float x = 0.f;
    float y = 0.f;
    bool alive = true;
};

