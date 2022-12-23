#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

struct Texture
{
    sf::Texture* texture = new sf::Texture();
    std::string name;
};


class TextureManager
{
    private:
        std::vector<Texture> textures;
    public:
        ~TextureManager();
        void addTexture(std::string filepath, std::string name);
        sf::Texture* getTexture(std::string name);
};