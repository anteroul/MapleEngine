#include "BoxCollider.h"
#include "../../Game.h"

void BoxCollider::initialize()
{
    Physics& physics = Game::getInstance().getPhysics();

    physics.collisionHandler(this, [this](Entity *collidedWith, b2Contact *contact)
    {
        b2Vec2 oldPosition = collidedWith->body->GetTransform().p;
        printf("%f, %f", oldPosition.x, oldPosition.y);
        printf("Collision detected %s!\n", collidedWith->getName().c_str());
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        collidedWith->body->SetTransform(oldPosition, this->getBody()->GetAngle());
    });
}
