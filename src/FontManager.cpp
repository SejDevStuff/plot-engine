#include "FontManager.hpp"

void FontManager::add_font(std::string font_path, std::string name)
{
    for (int i = 0; i < fonts.size(); i++)
    {
        if (fonts[i].name == name)
        {
            std::cout << "[PlotEngine/FontManager] Error: font name already exists";
            return;
        }
    }

    FontData newfont;
    if (!newfont.font->loadFromFile(font_path))
    {
        std::cout << "[PlotEngine/FontManager] Error: cannot load font";
        return;
    }

    newfont.name = name;
    fonts.push_back(newfont);
}

sf::Font* FontManager::get_font(std::string name)
{
    bool found = false;
    FontData foundFontDat;

    for (int i = 0; i < fonts.size(); i++)
    {
        if (fonts[i].name == name)
        {
            found = true;
            foundFontDat = fonts[i];
        }
    }
    if (!found)
    {
        std::cout << "[PlotEngine/FontManager] Error: cannot find font";
        return NULL;
    }
    return foundFontDat.font;
}

sf::Text FontManager::get_text(sf::Font* font, std::string string, int sz, sf::Color colour, sf::Uint32 style)
{
    sf::Text text;
    text.setFont(*font);
    text.setString(string);
    text.setCharacterSize(sz);
    text.setFillColor(colour);
    text.setStyle(style);
    return text;
}