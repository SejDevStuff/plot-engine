#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "StateManager.hpp"

struct GameData {
    StateManager stateman;
};

class Engine
{
    private:
        sf::RenderWindow window;
        GameData gd;
    public:
        void start(int screenWidth, int screenHeight, std::string title);
        void handleEvents(sf::Event& ev);
        void addState(State& state);
        StateManager& get_stateman() { return gd.stateman; }
        sf::RenderWindow& get_window() { return window; }
};