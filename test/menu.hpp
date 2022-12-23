#pragma once
#include "../src/Engine.hpp"

class MainMenu : public State
{
    private:
        /* data */
    public:
        MainMenu(GameData& gamedata);
        ~MainMenu();
        void handleEvents(sf::Event& e);
        void update();
        void render();
};