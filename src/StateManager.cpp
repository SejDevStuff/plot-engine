#include "StateManager.hpp"

void StateManager::add_state(State& state)
{
    states.push_back(&state);
}

void StateManager::pop_state()
{
    states.pop_back();
}

State& StateManager::get_state()
{
    return *(states.back());
}

int StateManager::get_states_num()
{
    return states.size();
}

void StateManager::change_state(State& state)
{
    while (states.size() != 0) {
        pop_state();
    }
    add_state(state);
}