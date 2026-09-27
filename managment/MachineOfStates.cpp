#include "StateMachine.h"
#include "Game.h"      //нужно создать класс самой игры (с графикой и логикой)

StateMachine::~StateMachine() {
    delete m_current;
    delete m_pending;
}

void StateMachine::changeState(IGameState* newState) {
    if (m_pending) {
        delete m_pending;
    }
    m_pending = newState;
}

void StateMachine::applyPending(Game& game) {
    if (!m_pending) return;

    if (m_current) {
        m_current->onExit(game);
        delete m_current;
    }
    m_current = m_pending;
    m_pending = nullptr;

    if (m_current) m_current->onEnter(game);
}

void StateMachine::update(Game& game, float dt) {
    applyPending(game);
    if (m_current) m_current->update(game, dt);
}

void StateMachine::render(Game& game) {
    if (m_current) m_current->render(game);
}

void StateMachine::handleInput(Game& game, const sf::Event& e) {
    if (m_current) m_current->handleInput(game, e);
}