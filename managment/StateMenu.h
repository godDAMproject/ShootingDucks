#pragma once
#include "IGameState.h"

class MenuState : public IGameState {
public:
    void onEnter(Game& game) override;
    void onExit(Game& game) override {}
    void handleInput(Game& game, const sf::Event& event) override;
    void update(Game& game, float deltaTime) override {}
    void render(Game& game) override;
};