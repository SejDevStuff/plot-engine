#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

class State
{
    private:
        StateManager& stateman;
    public:
        virtual void handleEvents(sf::Event& e) = 0;
        virtual void update() = 0;
        virtual void render(sf::RenderTarget& renderer) = 0;
};