#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "StateManager.hpp"

class Engine
{
    private:
        sf::RenderWindow window;
        GameData gd;
    public:
        void start(int screenWidth, int screenHeight, std::string title);
        void handleEvents(sf::Event& ev);
        void addState(State& state);
};