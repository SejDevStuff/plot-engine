#include "GUI.hpp"

void Button::update()
{
    _drawText.setPosition(sprite.getPosition());

    int width = sprite.getGlobalBounds().width;
    int height = sprite.getGlobalBounds().height;
    int xPos = sprite.getPosition().x;
    int yPos = sprite.getPosition().y;

    sf::Vector2i mousePos = sf::Mouse::getPosition(gd.window);

    mouseOver = false;
    pressed = false;

    if (mousePos.x >= xPos && mousePos.x <= (xPos + width))
    {
        if (mousePos.y >= yPos && mousePos.y <= (yPos + height))
        {
            mouseOver = true;
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                pressed = true;
            }
        }
    }
}

void Button::updateScale()
{
    sf::Vector2f scale;
    scale.x = (_drawText.getLocalBounds().width + 10) / sprite.getGlobalBounds().width;
    scale.y = (_drawText.getLocalBounds().height + 10) / sprite.getGlobalBounds().height;

    sprite.setScale(scale);
}

void Button::setText(std::string p_text)
{
    _drawText.setString(p_text);
    updateScale();
}

void Button::draw()
{
    gd.window.draw(sprite);
    gd.window.draw(_drawText);
}

bool Button::isPressedNoEcho()
{
    if (pressed)
    {
        if (!alreadyPressed)
        {
            alreadyPressed = true;
            return true;
        }
    } else {
        alreadyPressed = false;
    }
    return false;
}