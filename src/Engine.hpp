#include <SFML/Graphics.hpp>
#include <iostream>

class Engine
{
    private:
        sf::RenderWindow window;
    public:
        void start(int screenWidth, int screenHeight, std::string title);
};