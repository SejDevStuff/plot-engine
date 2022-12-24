#include "GUI.hpp"

void Button::update()
{
    int width = sprite.getTexture()->getSize().x;
    int height = sprite.getTexture()->getSize().y;
    int xPos = sprite.getPosition().x;
    int yPos = sprite.getPosition().y;

    sf::Vector2i mousePos = sf::Mouse::getPosition(gd.window);

    mouseOver = false;
    pressed = false;

    if (mousePos.x >= xPos && mousePos.x <= (xPos + width))
    {
        if (mousePos.x >= yPos && mousePos.y <= (yPos + width))
        {
            mouseOver = true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pressed = true;
            }
        }
    }
}

void Button::draw()
{
    gd.window.draw(sprite);
}