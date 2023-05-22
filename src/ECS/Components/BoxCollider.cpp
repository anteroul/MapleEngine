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
            {
                /*
                if (i->GetPosition().x > self->body->GetPosition().x)
                {
                    self->body->SetTransform(b2Vec2(self->body->GetPosition().x - 0.018f, self->body->GetPosition().y), self->body->GetAngle());
                    i->SetTransform(b2Vec2(i->GetPosition().x + 0.018f, i->GetPosition().y), i->GetAngle());
                }
                else
                {
                    self->body->SetTransform(b2Vec2(self->body->GetPosition().x + 0.018f, self->body->GetPosition().y), self->body->GetAngle());
                    i->SetTransform(b2Vec2(i->GetPosition().x - 0.018f, i->GetPosition().y), i->GetAngle());
                }
                */
            }
        }
    }
}