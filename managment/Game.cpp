#include "Game.h"
#include "MenuState.h"
#include "graphics/AssetManager.h"
#include <ctime>

Game::Game()
    : m_window(sf::VideoMode(800, 600), "Duck Hunt")
{
    m_window.setFramerateLimit(60);
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    AssetManager::instance().preloadAll();

    m_renderer = new Renderer(m_window);
    m_input    = new InputHandler(m_window);
    m_hunter   = new Hunter(400.f, 550.f);

    m_states.changeState(new MenuState());
}

Game::~Game() {
    delete m_hunter;
    delete m_input;
    delete m_renderer;
}

sf::Vector2f Game::getMousePosition() {
    return m_input->getMousePosition();
}

void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        float dt = clock.restart().asSeconds();
        sf::Event event;

        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                m_window.close();
                return;
            }
            m_states.handleInput(*this, event);
        }

        m_states.update(*this, dt);
        m_states.render(*this);
    }
}