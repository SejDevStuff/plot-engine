// Test file for engine
#include "../src/Engine.hpp"
#include "menu.hpp"

int main() {
    Engine e;
    GameData& gd = e.get_gamedata();

    std::unique_ptr<State> mainMenu(new MainMenu(gd));
    gd.stateman.change_state(std::move(mainMenu));

    e.start(400, 400, "Game");
    return 0;
}