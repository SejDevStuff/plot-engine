#include "second_scr.hpp"
#include "menu.hpp"

EntityManager entityman;

class Bob : public Actor
{
    public:
        Bob(GameData& gd) : Actor{gd} {
            gd.textman.addTexture("./bin/res/Test.png", "Bob");
        }
        void draw();
        void update();  
};

void Bob::draw()
{
    gd.window.draw(sprite);
}

void Bob::update()
{
    sf::Texture* tex = gd.textman.getTexture("Bob");
    if (tex != NULL)
    {
        sprite.setTexture(*tex);
    }
    sprite.setPosition(xPos, yPos);
}

void SecondScreen::handleEvents(sf::Event& e)
{
    switch (e.type)
    {
        case sf::Event::KeyPressed:
            if (e.key.code == sf::Keyboard::Space)
            {
                std::unique_ptr<State> mainMenu(new MainMenu(gd));
                gd.stateman.change_state(std::move(mainMenu));
                return;
            }
    }
}

int changeByX = 10;
int changeByY = 10;

void SecondScreen::update()
{
    Actor* bob = entityman.get_actor("Bob");
    if (bob != NULL)
    {
        // Make bob bounce back and forth, like the DVD logo

        if (bob->getX() < 0)
        {
            changeByX = 10;
        } else if (bob->getX()+bob->getHeight() > gd.window.getSize().x) {
            changeByX = -10;
        }

        if (bob->getY() < 0)
        {
            changeByY = 10;
        } else if (bob->getY()+bob->getWidth() > gd.window.getSize().y) {
            changeByY = -10;
        }

        bob->setPosition(bob->getX()+changeByX, bob->getY()+changeByY);
    }
    entityman.update();
}

void SecondScreen::render()
{
    entityman.render();
}


SecondScreen::SecondScreen(GameData& gamedata)
: State{ gamedata } 
{
    Bob* bob = new Bob(gamedata);
    entityman.add_actor(bob, "Bob");
}

SecondScreen::~SecondScreen()
{}