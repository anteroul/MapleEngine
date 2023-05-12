#include "BoxCollider.h"
#include "Gravity.h"
#include <iostream>

BoxCollider::BoxCollider(Entity& owner, Entity& ignore, b2World& world) : Component(owner)
{
    self = &owner;
    ignored = &ignore;
    bodyCount = world.GetBodyCount();
    auto bodyList = world.GetBodyList();

    for (int i = 0; i < bodyCount; ++i)
        bodies.emplace_back(bodyList->GetNext());
}

void BoxCollider::update(GLFWwindow *window, float deltaTime)
{
    for (auto i : bodies) {
        b2Vec2 pos1 = i->GetPosition();
        b2Vec2 pos2 = self->body->GetPosition();

        if (i != ignored->body && self->getComponment<Gravity>()) {
            float distance = pos1.x + pos2.x;

            if (distance < 0.04f || distance > -0.04f) {
                if (pos1.x < pos2.x)
                    self->body->SetTransform(b2Vec2(pos2.x + 0.001f, pos2.y), self->body->GetAngle());
                else
                    self->body->SetTransform(b2Vec2(pos2.x - 0.001f, pos2.y), self->body->GetAngle());
            }
        }
        std::cout << pos2.x << std::endl;
    }
}