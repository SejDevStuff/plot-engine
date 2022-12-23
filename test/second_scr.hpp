#pragma once
#include "../src/Engine.hpp"

class SecondScreen : public State
{
    private:
        /* data */
    public:
        SecondScreen(GameData& gamedata);
        ~SecondScreen();
        void handleEvents(sf::Event& e);
        void update();
        void render();
};