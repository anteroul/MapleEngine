#include "Game.h"
#include "GameObjects/Player.h"
#include "GameObjects/Wall.h"
#include "ECS/Components/PlayerInput.h"
#include "ECS/Components/SphereRenderer.h"
#include <GLFW/glfw3.h>
#include <algorithm>
#include <iostream>

Game Game::gameInstance;

Game& Game::getInstance()
{
    return gameInstance;
}

Game::Game() = default;

void Game::initialize()
{
    auto player = new Entity();

    b2World& world = physics.getWorld();
    b2BodyDef playerBodyDef;
    playerBodyDef.position.Set(0.f, 0.f);
    player->body = world.CreateBody(&playerBodyDef);
    player->setName("Player");
    player->addTag("Player");
    player->addComponent(new SphereRenderer(*player, 0.01f));
    player->addComponent(new PlayerInput(*player, 8000.f));

    entities.push_back(new Wall(world, b2Vec2(-1.f, -0.5f), b2Vec2(1.f, -0.4f)));
    entities.push_back(player);

    for (auto i : entities)
        i->initialize();
}

void Game::update(GLFWwindow* window, float deltaTime)
{
    physics.update(deltaTime);

    Entity* player = getEntityWithName("Player");

    for (auto entity : entities)
        entity->update(window, deltaTime);

    std::cout << player->body->GetTransform().p.x << ", " << player->body->GetTransform().p.y << std::endl;
}

void Game::render()
{
    for (auto entity : entities)
        entity->render();
}

void Game::setEntityName(Entity* entity, const std::string& name)
{
    names.insert(std::pair<std::string, Entity*>(name, entity));
}

void Game::removeEntityName(Entity* entity, const std::string& name)
{
    names.erase(name);
}

Entity* Game::getEntityWithName(const std::string& name) const
{
    auto it = names.find(name);

    if (it == names.end())
        return nullptr;
    else
        return it->second;
}

void Game::addEntityTag(Entity* entity, const std::string& tag)
{
    auto it = tags.find(tag);

    if (it == tags.end())
    {
        auto inserted = tags.insert(std::pair<std::string, std::list<Entity*>>());
        it = inserted.first;
    }

    it->second.push_back(entity);
}

void Game::removeEntityTag(Entity* entity, const std::string& tag)
{
    auto it = tags.find(tag);

    if (it == tags.end())
        return;

    auto entities = it->second;
    auto entityIt = std::find(entities.begin(), entities.end(), entity);

    if (entityIt == entities.end())
        return;

    entities.erase(entityIt);
}

std::list<Entity*> Game::getEntitiesWithTag(const std::string& tag) const
{
    auto it = tags.find(tag);

    if (it == tags.end())
        return std::list<Entity*>();
    else
        return it->second;
}

Entity* Game::getEntityWithTag(const std::string& tag) const
{
    auto entities = getEntitiesWithTag(tag);
    auto it = entities.begin();

    if (it == entities.end())
        return nullptr;
    else
        return *it;
}