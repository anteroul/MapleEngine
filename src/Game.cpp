#include "Game.h"
#include "ECS/Components/PlayerInput.h"
#include "ECS/Components/BoxRenderer.h"
#include "ECS/Components/BoxCollider.h"
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
    b2World& world = physics.getWorld();

    auto ball = new Entity(world, b2Vec2(-0.2f, 0.2f), b2Vec2(0.2f, -0.2f));
    ball->setName("ball");
    ball->addComponent(new PlayerInput(*ball, 0.0018f));
    ball->addComponent(new SphereRenderer(*ball, 0.2f, {0.f, 1.f, 1.f}));
    ball->addComponent(new BoxCollider(*ball));

    auto wall1 = new Entity(world, b2Vec2(-1.f, 1.f), b2Vec2(1.f, 0.8f));
    wall1->setName("wall1");
    wall1->addComponent(new BoxCollider(*wall1));
    wall1->addComponent(new BoxRenderer(*wall1, {1.f, 0.2f}, {1.f, 0.f, 0.f}));

    auto wall2 = new Entity(world, b2Vec2(-1.f, 1.f), b2Vec2(-0.8f, -1.f));
    wall2->setName("wall2");
    wall2->addComponent(new BoxCollider(*wall2));
    wall2->addComponent(new BoxRenderer(*wall2, {0.2f, 1.f}, {1.f, 0.f, 1.f}));

    auto wall3 = new Entity(world, b2Vec2(0.8f, 1.f), b2Vec2(1.f, -1.f));
    wall3->setName("wall3");
    wall3->addComponent(new BoxCollider(*wall3));
    wall3->addComponent(new BoxRenderer(*wall3, {0.2f, 1.f}, {0.f, 1.f, 0.f}));

    auto wall4 = new Entity(world, b2Vec2(-1.f, -0.8f), b2Vec2(1.f, -1.f));
    wall4->setName("wall4");
    wall4->addComponent(new BoxCollider(*wall4));
    wall4->addComponent(new BoxRenderer(*wall4, {1.f, 0.2f}, {1.f, 1.f, 0.f}));

    entities.push_back(ball);
    entities.push_back(wall1);
    entities.push_back(wall2);
    entities.push_back(wall3);
    entities.push_back(wall4);

    for (auto i : entities)
        i->initialize();
}

void Game::update(GLFWwindow* window, float deltaTime)
{
    physics.update(deltaTime);

    for (auto entity : entities)
        entity->update(window, deltaTime);
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