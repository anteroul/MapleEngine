#include "Scene2D.h"
#include <iostream>

Scene2D::Scene2D()
{
    auto c = GameObject("Cursor", {0.f, 0.f}, {0.01f, 0.01f}, {255, 0, 0, 255}, false, false);
    auto rigidBody = GameObject("Green", {-0.8f, 0.3f}, {0.1f, 0.2f}, {0, 255, 0, 255}, true, true);
    auto floor = GameObject("Ground", {0.f, -0.5f}, {2.f, 0.2f}, {8, 8, 8, 255}, true, false);

    gravity = b2Vec2(0.f, -10.f);
    world = new b2World(gravity);

    gameObjects.emplace_back(c);
    gameObjects.emplace_back(rigidBody);
    gameObjects.emplace_back(floor);
}

Scene2D::~Scene2D()
{
    delete world;
}

void Scene2D::UpdateScene(float xPos, float yPos)
{
    glm::vec2 mousePos = {xPos, yPos};

    for (auto & gameObject : gameObjects)
    {
        if (gameObject.GetTagName() == "Cursor")
        {
            gameObject.MoveTo(mousePos);
        }
    }

}

void Scene2D::RenderScene()
{
    for (auto & gameObject : gameObjects)
        gameObject.Render();
}