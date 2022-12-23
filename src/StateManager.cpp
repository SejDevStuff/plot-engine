#include "StateManager.hpp"

void StateManager::add_state(std::unique_ptr<State> state)
{
    states.push(std::move(state));
}

void StateManager::pop_state()
{
    states.pop();
}

int StateManager::get_states_num()
{
    return states.size();
}

void StateManager::change_state(std::unique_ptr<State> state)
{
    while (!states.empty()) {
        pop_state();
    }
    add_state(std::move(state));
}

StateManager::~StateManager()
{
    while (!states.empty()) {
        pop_state();
    }
}

void StateManager::render()
{
    states.top()->render();
}

void StateManager::update()
{
    states.top()->update();
}

void StateManager::handleEvents(sf::Event &e)
{
    states.top()->handleEvents(e);
}