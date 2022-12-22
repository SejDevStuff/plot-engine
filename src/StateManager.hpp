#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "State.hpp"

class StateManager
{
    private:
        std::vector<State*> states;
    public:
        void add_state(State& state);
        void pop_state();
        void change_state(State& state);
        int get_states_num();
        State& get_state();
        std::vector<State*> get_states_list() { return states; }
};