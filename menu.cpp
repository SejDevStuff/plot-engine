#include "menu.hpp"

void MainMenu::handleEvents(sf::Event& e)
{
    // ...
}

void MainMenu::update()
{
}

void MainMenu::render(sf::RenderTarget& renderer)
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    renderer.draw(shape);
}