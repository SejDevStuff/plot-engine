#include "src/Engine.hpp"

class MainMenu : public State
{
    private:
        /* data */
    public:
        void handleEvents(sf::Event& e);
        void update();
        void render(sf::RenderTarget& renderer);
};