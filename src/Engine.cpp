#include "Engine.hpp"

void Engine::start(int screenWidth, int screenHeight, std::string title)
{
    window.create(sf::VideoMode(screenWidth, screenHeight), title);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}