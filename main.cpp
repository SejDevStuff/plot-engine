// Test file for engine
#include "src/Engine.hpp"
#include "menu.hpp"

int main() {
    Engine e;
    MainMenu main_menu;
    e.addState(main_menu);
    e.start(400, 400, "Game");
    return 0;
}