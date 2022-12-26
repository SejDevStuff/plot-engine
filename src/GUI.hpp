#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Engine.hpp"
#include "Actor.hpp"


class Button : public Actor
{
    private:
        bool pressed = false;
        bool mouseOver = false;
        bool alreadyPressed = false;
        sf::Text _drawText;

        sf::Texture& normal_tex;
    public:
        Button(GameData& gamedata, sf::Texture& normalTexture, sf::Text drawText) 
            : normal_tex{normalTexture}, Actor{gamedata}, _drawText{drawText}
            { 
                normal_tex.setRepeated(true); 
                sprite.setTexture(normal_tex); 
            }
        
        bool isPressed()                            { return pressed; }
        bool isMouseOver()                          { return mouseOver; }
        void setText(std::string p_text);
        bool isPressedNoEcho();
        void update();
        void draw();
        void updateScale();
};
