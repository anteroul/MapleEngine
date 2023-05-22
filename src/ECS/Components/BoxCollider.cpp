#include "BoxCollider.h"
#include "Gravity.h"

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
    b2Vec2 oldPos = self->body->GetPosition();

    for (auto i : bodies)
    {
        if (i != ignored->body && self->getComponment<Gravity>())
        {
            b2Vec2 self_v1(self->body->GetPosition().x - (self->size.x / 2), self->body->GetPosition().y);
            b2Vec2 self_v2(self->body->GetPosition().x + (self->size.x / 2), self->body->GetPosition().y);
            b2Vec2 other_v1(i->GetPosition().x - (i->GetPosition().x / 2), i->GetPosition().y);
            b2Vec2 other_v2(i->GetPosition().x + (i->GetPosition().x / 2), i->GetPosition().y);

            b2EdgeShape selfEdge, other;

            selfEdge.Set(self_v1, other_v1);
            other.Set(self_v2, other_v2);

            if (b2TestOverlap(&selfEdge, 2, &other, 2, self->body->GetTransform(), i->GetTransform()))
                self->body->SetTransform(oldPos, self->body->GetAngle());
        }
    }
}