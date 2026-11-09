#include "GameLogic.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

GameLogic::GameLogic() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void GameLogic::update(float deltaTime) {
    if (isGameOver()) return;

    // Спавн уток по таймеру
    spawnTimer += deltaTime;
    if (spawnTimer >= spawnInterval) {
        spawnDuck();
        spawnTimer = 0.f;
    }

    // Обновление охотника
    hunter.update(deltaTime);

    // Обновление уток
    for (auto& duck : ducks) {
        duck->update(deltaTime);
    }

    // Обновление пуль
    for (auto& bullet : bullets) {
        bullet->update(deltaTime);
    }

    // Проверка столкновений и очистка
    checkCollisions();
    cleanup();
}

void GameLogic::draw(sf::RenderWindow& window) const {
    for (const auto& duck : ducks) {
        duck->draw(window);
    }

    for (const auto& bullet : bullets) {
        bullet->draw(window);
    }

    hunter.draw(window);
}

void GameLogic::handleMouseMoved(float mouseX, float mouseY) {
    hunter.setMousePosition(mouseX, mouseY);
}

void GameLogic::handleMouseClick(float clickX, float clickY) {
    bullets.push_back(std::make_unique<Bullet>(
        hunter.getX(), hunter.getY(), clickX, clickY
    ));
}

void GameLogic::spawnDuck() {
    float y = static_cast<float>(std::rand() % 400 + 100);
    float speed = static_cast<float>(std::rand() % 150 + 100);

    int roll = std::rand() % 100;
    std::unique_ptr<Duck> duck;

    if (roll < 5) {
        duck = std::make_unique<GoldenDuck>(-50.f, y, speed);
    } else if (roll < 15) {
        duck = std::make_unique<BombDuck>(-50.f, y, speed);
    } else {
        duck = std::make_unique<Duck>(-50.f, y, speed);
    }

    ducks.push_back(std::move(duck));
}

void GameLogic::checkCollisions() {
    for (auto& bullet : bullets) {
        if (!bullet->isAlive()) continue;

        for (auto& duck : ducks) {
            if (!duck->isAlive()) continue;

            if (duck->collidesWith(
                    bullet->getX(), bullet->getY(), bullet->getRadius())) {

                score += duck->getScore();

                if (duck->isDangerous()) {
                    lives--;
                }

                duck->setPosition(-1000.f, -1000.f);
                break;
            }
        }
    }
}

void GameLogic::cleanup() {
    ducks.erase(
        std::remove_if(ducks.begin(), ducks.end(),
            [](const std::unique_ptr<Duck>& d) { return !d->isAlive(); }),
        ducks.end()
    );

    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [](const std::unique_ptr<Bullet>& b) { return !b->isAlive(); }),
        bullets.end()
    );
}