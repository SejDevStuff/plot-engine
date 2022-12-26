#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

struct FontData
{
    sf::Font* font = new sf::Font();
    std::string name;
};

class FontManager
{
    private:
        std::vector<FontData> fonts;
    public:
        void add_font(std::string font_path, std::string name);
        sf::Font* get_font(std::string name);
        sf::Text get_text(sf::Font* font, std::string string, int sz, sf::Color colour, sf::Uint32 style = sf::Text::Regular);
};  