#pragma once

#include "logic/GameObject.h"
#include "logic/Bullet.h"

class Hunter : public GameObject {
public:
    Hunter();

    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;

    // ИНКАПСУЛЯЦИЯ: координаты мыши передаются извне
    void setMousePosition(float mouseX, float mouseY);

    // Стрельба — создаёт пулю в текущей позиции
    Bullet shoot(float targetX, float targetY) const;

    int getAmmo() const { return ammo; }
    void reload() { ammo = maxAmmo; }

private:
    float size = 30.f;
    int ammo = 6;
    int maxAmmo = 6;
};