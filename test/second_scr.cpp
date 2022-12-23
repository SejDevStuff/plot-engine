#include "second_scr.hpp"
#include "menu.hpp"

void SecondScreen::handleEvents(sf::Event& e)
{
    switch (e.type)
    {
        case sf::Event::KeyPressed:
            if (e.key.code == sf::Keyboard::Space)
            {
                std::unique_ptr<State> mainMenu(new MainMenu(gd));
                gd.stateman.change_state(std::move(mainMenu));
                return;
            }
    }
}

void SecondScreen::update()
{
}

void SecondScreen::render()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    gd.window.draw(shape);
}


SecondScreen::SecondScreen(GameData& gamedata)
: State{ gamedata } {}

SecondScreen::~SecondScreen()
{}