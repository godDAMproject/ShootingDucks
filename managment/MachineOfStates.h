#pragma once
#include "GameState.h"

class StateMachine {
public:
    StateMachine() = default;
    ~StateMachine();

    StateMachine(const StateMachine&) = delete;
    StateMachine& operator=(const StateMachine&) = delete;

    void changeState(IGameState* newState);
    void update(Game& game, float dt);
    void render(Game& game);
    void handleInput(Game& game, const sf::Event& e);

private:
    IGameState* m_current = nullptr;
    IGameState* m_pending = nullptr;

    void applyPending(Game& game);
};