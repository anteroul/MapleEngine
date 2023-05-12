#include "BoxCollider.h"
#include "Gravity.h"

BoxCollider::BoxCollider(Entity& owner, Entity& ignore, b2World& world) : Component(owner)
{
    self = &owner;
    ignored = &ignore;
    bodyCount = world.GetBodyCount();
    auto bodyList = world.GetBodyList();

    for (int i = 0; i < bodyCount; ++i) {
        bodies.emplace_back(bodyList->GetNext());
    }
}

void BoxCollider::update(GLFWwindow *window, float deltaTime)
{
    for (auto i : bodies)
    {
        b2Vec2 pos1 = i->GetPosition();
        b2Vec2 pos2 = self->body->GetPosition();

        if (i != ignored->body)
        {
            if (self->getComponment<Gravity>())
            {
                if (pos1.x - 0.01f >= pos2.x - 0.001f && pos1.y - 0.001f <= pos2.y + 0.001f)
                {
                    self->body->SetTransform(b2Vec2(pos2.x - 0.0009f, pos2.y), self->body->GetAngle());
                }
                if (pos1.x + 0.01f <= pos2.x - 0.001f && pos1.y - 0.001f <= pos2.y + 0.001f)
                {
                    self->body->SetTransform(b2Vec2(pos2.x + 0.0009f, pos2.y), self->body->GetAngle());
                }
            }
        }
    }
    Component::update(window, deltaTime);
}
