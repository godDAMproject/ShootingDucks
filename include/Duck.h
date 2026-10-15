#pragma once

#include "GameObject.h"

// Базовый класс утки
class Duck : public GameObject {
public:
    Duck(float startX, float startY, float speed);
    virtual ~Duck() = default;

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

    // Виртуальные методы для полиморфизма
    virtual int getScore() const { return 10; }
    virtual bool isDangerous() const { return false; }
    virtual sf::Color getColor() const { return sf::Color::White; }

    // Проверка столкновения с пулей
    bool collidesWith(float bulletX, float bulletY, float bulletRadius) const;

    // Получение границ для коллизий
    sf::FloatRect getBounds() const;

protected:
    float speed;
    float size = 40.f;
};

// Золотая утка — больше очков
class GoldenDuck : public Duck {
public:
    GoldenDuck(float startX, float startY, float speed);

    int getScore() const override { return 100; }
    sf::Color getColor() const override { return sf::Color::Yellow; }
};

// Утка-бомба — отнимает жизни
class BombDuck : public Duck {
public:
    BombDuck(float startX, float startY, float speed);

    int getScore() const override { return -50; }
    bool isDangerous() const override { return true; }
    sf::Color getColor() const override { return sf::Color::Red; }
};
