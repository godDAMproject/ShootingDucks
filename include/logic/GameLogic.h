#pragma once

#include "logic/Duck.h"
#include "logic/Bullet.h"
#include "logic/Hunter.h"
#include <vector>
#include <memory>

class GameLogic {
public:
    GameLogic();

    // Обновление всей логики (вызывается каждый кадр)
    void update(float deltaTime);

    // Отрисовка всех объектов
    void draw(sf::RenderWindow& window) const;

    // Обработка ввода
    void handleMouseMoved(float mouseX, float mouseY);
    void handleMouseClick(float clickX, float clickY);

    // Геттеры состояния игры
    int getScore() const { return score; }
    int getLives() const { return lives; }
    bool isGameOver() const { return lives <= 0; }

private:
    Hunter hunter;
    std::vector<std::unique_ptr<Duck>> ducks;
    std::vector<std::unique_ptr<Bullet>> bullets;

    int score = 0;
    int lives = 3;

    float spawnTimer = 0.f;
    float spawnInterval = 1.5f;

    void spawnDuck();
    void checkCollisions();
    void cleanup();
};