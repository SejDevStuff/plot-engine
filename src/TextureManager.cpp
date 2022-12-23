#include "TextureManager.hpp"

void TextureManager::addTexture(std::string filepath, std::string name)
{
    bool foundTex = false;
    for (int i = 0; i < textures.size(); i++)
    {
        Texture tex = textures[i];
        if (tex.name == name)
        {
            foundTex = true;
        }
    }

    if (foundTex)
    {
        std::cout << "[PlotEngine/TextureManager] Error: texture already exists" << std::endl;
        return;
    }

    Texture texToAdd;
    if (!texToAdd.texture->loadFromFile(filepath))
    {
        std::cout << "[PlotEngine/TextureManager] Error: cannot load texture" << std::endl;
        return;
    }
    
    texToAdd.name = name;
    textures.push_back(texToAdd);
}

sf::Texture* TextureManager::getTexture(std::string name)
{
    bool foundTex = false;
    Texture found;

    for (int i = 0; i < textures.size(); i++)
    {
        Texture tex = textures[i];
        if (tex.name == name)
        {
            foundTex = true;
            found = tex;
        }
    }
    if (!foundTex)
    {
        std::cout << "[PlotEngine/TextureManager] Error: cannot find texture" << std::endl;
        return NULL;
    } else {
        return found.texture;
    }
}

TextureManager::~TextureManager()
{
    while (!textures.empty())
    {
        textures.pop_back();
    }
}