#pragma once
#include <SFML/Graphics.hpp>

class StateManager;

class State
{
    public:
        State(GameData& gamedata) : gd{gamedata} {}
        virtual ~State() {}
        virtual void handleEvents(sf::Event& e) = 0;
        virtual void update() = 0;
        virtual void render() = 0;
    protected:
        GameData& gd;
};