#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

struct GameData;

#include "StateManager.hpp"
#include "TextureManager.hpp"
#include "EntityManager.hpp"
#include "Actor.hpp"

struct GameData {
    StateManager stateman;
    sf::RenderWindow window;
    TextureManager textman;
};

#include "GUI.hpp"

class Engine
{
    private:
        GameData gd;
    public:
        void start(int screenWidth, int screenHeight, std::string title);
        void handleEvents(sf::Event& ev);
        GameData& get_gamedata() { return gd; }
};