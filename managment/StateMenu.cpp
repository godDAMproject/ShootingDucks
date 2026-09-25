#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"

void MenuState::onEnter(Game&) {}

void MenuState::handleInput(Game& game, const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Enter) {
        game.getStateMachine().changeState(new PlayState());
    }
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape) {
        game.getWindow().close();
    }
}

void MenuState::render(Game& game) {
    game.getRenderer().clear();
    game.getRenderer().drawText("DUCK HUNT", 260.f, 200.f, 48, sf::Color::Black);
    game.getRenderer().drawText("Press ENTER to start", 280.f, 300.f, 24);
    game.getRenderer().drawText("ESC to exit", 320.f, 340.f, 20);
    game.getRenderer().display();
}