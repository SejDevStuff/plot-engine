#include "EntityManager.hpp"

void EntityManager::add_actor(Actor* actor, std::string name)
{
    for (int i = 0; i < actors.size(); i++)
    {
        if (actors[i].name == name)
        {
            std::cout << "[PlotEngine/EntityManager] Error: actor name already used" << std::endl;
            return;
        }
    }

    ActorStore _actor;
    _actor.actor = actor;
    _actor.name = name;
    actors.push_back(_actor);
}

Actor* EntityManager::get_actor(std::string name)
{
    bool found = false;
    ActorStore _actor;

    for (int i = 0; i < actors.size(); i++)
    {
        if (actors[i].name == name)
        {
            found = true;
            _actor = actors[i];
        }
    }
    if (!found)
    {
        std::cout << "[PlotEngine/EntityManager] Error: actor doesn't exist" << std::endl;
        return NULL;
    }
    return _actor.actor;
}

void EntityManager::update()
{
    for (int i = 0; i < actors.size(); i++)
    {
        actors[i].actor->update();
    }
}

void EntityManager::render()
{
    for (int i = 0; i < actors.size(); i++)
    {
        actors[i].actor->draw();
    }
}

EntityManager::~EntityManager()
{
    while (!actors.empty())
    {
        actors.pop_back();
    }
}