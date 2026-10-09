#pragma once
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "graphics/Renderer.h"
#include "graphics/InputHandler.h"
#include "entities/Hunter.h"

class Game {
public:
    Game();
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();

    sf::RenderWindow& getWindow()        { return m_window; }
    Renderer&         getRenderer()      { return *m_renderer; }
    Hunter&           getHunter()        { return *m_hunter; }
    StateMachine&     getStateMachine()  { return m_states; }
    sf::Vector2f      getMousePosition();

private:
    sf::RenderWindow m_window;
    StateMachine m_states;
    Renderer*     m_renderer = nullptr;
    InputHandler* m_input    = nullptr;
    Hunter*       m_hunter   = nullptr;
};