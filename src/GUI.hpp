#pragma once
#include <SFML/Graphics.hpp>

#include "Engine.hpp"
#include "Actor.hpp"


class Button : public Actor
{
    private:
        bool pressed = false;
        bool mouseOver = false;

        sf::Texture& normal_tex;
    public:
        Button(GameData& gamedata, sf::Texture& normalTexture) 
            : normal_tex{normalTexture}, Actor{gamedata} { sprite.setTexture(normal_tex); }
        bool isPressed()                            { return pressed; }
        bool isMouseOver()                          { return mouseOver; }
        void update();
        void draw();
};
