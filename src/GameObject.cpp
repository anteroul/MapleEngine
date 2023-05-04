#include <utility>
#include <iostream>
#include "GameObject.h"

#define SPEED 0.0017f

GameObject::GameObject(std::string name, glm::vec2 pos, glm::vec2 _scale, glm::vec4 _colour, bool setDynamic, bool applyPhysics)
: tagName(std::move(name)), hasCollider(setDynamic), hasRigidBody(applyPhysics)
{
    position = pos;
    scale = _scale;
    colour = _colour;
}

GameObject::~GameObject() = default;

std::string GameObject::GetTagName()
{
    return tagName;
}

void GameObject::MoveTo(glm::vec2 pos) const
{
    if (position.x < pos.x)
        pos.x += SPEED;
    if (position.x > pos.x)
        pos.x -= SPEED;
    if (position.y < pos.y)
        pos.y += SPEED;
    if (position.y > pos.y)
        pos.y -= SPEED;
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

