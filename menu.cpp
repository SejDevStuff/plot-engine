#include "src/Engine.hpp"

class MainMenu : public State
{
    private:
        /* data */
    public:
        MainMenu(StateManager& stateman, sf::RenderWindow& window);
        void handleEvents(sf::Event& e);
        void update();
        void render();
};

void MainMenu::handleEvents(sf::Event& e)
{
    // ...
}

void MainMenu::update()
{
}

void MainMenu::render()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    g_win.draw(shape);
}


MainMenu::MainMenu(StateManager& stateman, sf::RenderWindow& window)
: State{ stateman, window } {
    std::cout << "[MainMenu] Initialised\n";
}