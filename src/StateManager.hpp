#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include <iostream>
#include <memory>

struct GameData;

#include "State.hpp"

class StateManager
{
    private:
        std::stack<std::unique_ptr<State>> states;
    public:
        ~StateManager();
        void add_state(std::unique_ptr<State> state);
        void pop_state();
        void change_state(std::unique_ptr<State> state);
        int get_states_num();
        void render();
        void update();
        void handleEvents(sf::Event& ev);
};