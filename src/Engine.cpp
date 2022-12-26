#include "Engine.hpp"

void Engine::handleEvents(sf::Event& ev) 
{
    while (gd.window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            gd.window.close();
        else
            gd.stateman.handleEvents(ev);
    }
}

int GameData::randi_range(int min, int max)
{
    return (rand() % max) + min;
}

void Engine::start(int screenWidth, int screenHeight, std::string title)
{
    std::cout << "PlotEngine v1.0.0" << std::endl;
    srand(time(NULL));
    gd.window.create(sf::VideoMode(screenWidth, screenHeight), title, sf::Style::Titlebar | sf::Style::Close);
    gd.window.setFramerateLimit(60);
    sf::Event event;

    while (gd.window.isOpen())
    {
        handleEvents(event);
        gd.stateman.update();
        gd.window.clear();
        gd.stateman.render();
        gd.window.display();
    }
}