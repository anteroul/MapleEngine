#include "Scene2D.h"
#include <iostream>

Scene2D::Scene2D(int w, int h) : w_Width(w), w_Height(h)
{
    auto c = GameObject("Cursor", {0.f, 0.f}, {0.01f, 0.01f}, {255, 0, 0, 255}, false, false);
    auto rigidBody = GameObject("Green", {-0.8f, 0.3f}, {0.1f, 0.2f}, {0, 255, 0, 255}, true, true);
    auto floor = GameObject("Ground", {0.f, -0.5f}, {2.f, 0.2f}, {8, 8, 8, 255}, true, false);

    gameObjects.emplace_back(rigidBody);
    gameObjects.emplace_back(floor);
    gameObjects.emplace_back(c);
}

Scene2D::~Scene2D() = default;

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

glm::vec2 Scene2D::ToVec2(float x, float y)
{
    x = x - (w_Width / 2);
    y = y - (w_Height / 2);
    y *= -1;
    x /= (w_Width / 2);
    y /= (w_Height / 2);

    return {x, y};
}
