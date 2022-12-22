// Test file for engine
#include "src/Engine.hpp"
#include "menu.cpp"

int main() {
    Engine e;
    StateManager& stateman = e.get_stateman();
    sf::RenderWindow& window = e.get_window();
    MainMenu mainMenu(stateman, window);
    
    e.addState(mainMenu);
    e.start(400, 400, "Game");
    return 0;
}