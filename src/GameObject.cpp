#include "constants/msg.h"
#include "GameObject.h"
#include <utility>
#include <iostream>

GameObject::GameObject(std::string name, glm::vec2 pos, glm::vec2 _scale, glm::vec4 _colour, bool setDynamic, bool applyPhysics)
: tagName(std::move(name)), hasCollider(setDynamic), hasRigidBody(applyPhysics)
{
    position = pos;
    scale = _scale;
    colour = _colour;
}

GameObject::~GameObject() = default;

void GameObject::UpdateData(std::shared_ptr<std::vector<GameObject>> data)
{
    sceneData = std::move(data);
}

void GameObject::Update()
{
    if (hasCollider)
    {
        for (auto & i : *sceneData)
            CheckCollision(&i);
    }
    if (hasRigidBody)
    {
        UpdatePhysics();
    }
    UpdateLogic();
    Render();
}

void GameObject::Render() const
{
    glBegin(GL_QUADS);
    glColor4f(colour.r, colour.g, colour.b, colour.a);
    glVertex2f(position.x - scale.x, position.y + scale.y);
    glVertex2f(position.x + scale.x, position.y + scale.y);
    glVertex2f(position.x + scale.x, position.y - scale.y);
    glVertex2f(position.x - scale.x, position.y - scale.y);
    glEnd();
    glFlush();
}

void GameObject::UpdateLogic()
{
    std::cout << "\n" << INFO << "Position: " << position.x << ", " << position.y << std::endl;
}

bool GameObject::CheckCollision(GameObject *other)
{
    // TODO
    if (other->hasCollider)
    {
        if (position.x + scale.x <= other->position.x - other->scale.x
        && position.y + scale.y <= other->position.y - other->scale.y
        && position.x - scale.x >= other->position.x - other->scale.x
        && position.y - scale.y >= other->position.x + other->scale.x)
        {
            return true;
        }
    }
    return false;
}

void GameObject::UpdatePhysics()
{
    for (auto & i : *sceneData)
        if (!CheckCollision(&i))
            position.y -= 0.0017f;
}