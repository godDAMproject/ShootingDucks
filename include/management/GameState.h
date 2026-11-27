#pragma once
#include <SFML/Graphics.hpp>

class Game;

class IGameState {
public:
    virtual ~IGameState() = default;
    virtual void onEnter(Game& game) = 0;
    virtual void onExit(Game& game) = 0;
    virtual void handleInput(Game& game, const sf::Event& event) = 0;
    virtual void update(Game& game, float deltaTime) = 0;
    virtual void render(Game& game) = 0;
};