#pragma once

#include <vector>
#include <iostream>
#include "Actor.hpp"

struct ActorStore
{
    Actor* actor;
    std::string name;
};


class EntityManager
{
    private:
        std::vector<ActorStore> actors;
    public:
        void add_actor(Actor* actor, std::string name);
        Actor* get_actor(std::string name);
        void update();
        void render();
        ~EntityManager();
};