#include "menu.hpp"
#include "second_scr.hpp"

void MainMenu::handleEvents(sf::Event& e)
{
    switch (e.type)
    {
        case sf::Event::KeyPressed:
            if (e.key.code == sf::Keyboard::Space)
            {
                std::unique_ptr<State> secondScr(new SecondScreen(gd));
                gd.stateman.change_state(std::move(secondScr));
            }
            break;
    }
}

void MainMenu::update()
{
}

void MainMenu::render()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    gd.window.draw(shape);
}


MainMenu::MainMenu(GameData& gamedata)
: State{ gamedata } {}

MainMenu::~MainMenu()
{}