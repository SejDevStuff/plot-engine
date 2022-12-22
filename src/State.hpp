#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

class State
{
    public:
        State(StateManager& stateman, sf::RenderWindow& window) : g_stateman{stateman}, g_win{window} {}
        virtual void handleEvents(sf::Event& e) = 0;
        virtual void update() = 0;
        virtual void render() = 0;
    protected:
        StateManager& g_stateman;
        sf::RenderWindow& g_win;
};