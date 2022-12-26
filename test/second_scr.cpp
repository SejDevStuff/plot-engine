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
bool alreadyPressed = false;

int r = 255;
int g = 255;
int b = 255;

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

    Button* button = entityman.get_actor_as_different_class<Button>("Button");
    button->setPosition(100, 100);

    entityman.update();

    if (button->isPressedNoEcho())
    {
        r = gd.randi_range(127, 255);
        g = gd.randi_range(127, 255);
        b = gd.randi_range(127, 255);
    }
}

void SecondScreen::render()
{
    entityman.render();
    sf::Text txt = gd.fontman.get_text(gd.fontman.get_font("Roboto"), "HELLO, WORLD", 50, sf::Color(r, g, b), sf::Text::Bold);
    gd.window.draw(txt);
}


SecondScreen::SecondScreen(GameData& gamedata)
: State{ gamedata } 
{
    gd.textman.addTexture("./bin/res/Button.png", "Button");
    gd.fontman.add_font("./bin/res/Roboto-Regular.ttf", "Roboto");
    
    Bob* bob = new Bob(gamedata);
    Button* btn = new Button(gamedata, *gd.textman.getTexture("Button"), gd.fontman.get_text(gd.fontman.get_font("Roboto"), "Button!", 32, sf::Color::White, sf::Text::Bold) );
    btn->setText("Change colour!");

    entityman.add_actor(bob, "Bob");
    entityman.add_actor(btn, "Button");
}

SecondScreen::~SecondScreen()
{}