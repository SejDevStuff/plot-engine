#include "Engine.hpp"

void Engine::handleEvents(sf::Event& ev) 
{
    while (window.pollEvent(ev))
    {
        if (ev.type == sf::Event::Closed)
            window.close();
        else
            gd.stateman.get_state().handleEvents(ev);
    }
}

void Engine::start(int screenWidth, int screenHeight, std::string title)
{
    window.create(sf::VideoMode(screenWidth, screenHeight), title);
    window.setFramerateLimit(60);
    sf::Event event;

    while (window.isOpen())
    {
        handleEvents(event);
        gd.stateman.get_state().update();
        window.clear();
        gd.stateman.get_state().render();
        window.display();
    }
}

void Engine::addState(State& state)
{
    gd.stateman.add_state(state);
}