#pragma once

#include <SFML/Graphics.hpp>

struct GameData;

class Actor
{
    protected:
        int xPos, yPos;
        sf::Sprite sprite;
        GameData& gd;

    public:
        Actor(GameData& gamedata) : gd{gamedata} {}

        void setPosition(int x, int y)          { xPos = x; yPos = y; sprite.setPosition(xPos, yPos); }
        int getX()                              { return xPos; }
        int getY()                              { return yPos; }
        int getHeight()                         { return sprite.getTextureRect().height; }
        int getWidth()                          { return sprite.getTextureRect().width; }
        sf::Sprite& getSprite()                 { return sprite; }

        virtual void draw() = 0;
        virtual void update() = 0;
};