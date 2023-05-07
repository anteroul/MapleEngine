#include "BoxCollider.h"
#include "../../Game.h"

void BoxCollider::initialize() {
    renderer = getComponent<BoxRenderer>();

    Physics& physics = Game::getInstance().getPhysics();
    physics.collisionHandler(this, [this](Entity *collidedWith, b2Contact *contact)
    {
        printf("Collision detected %s!\n", collidedWith->getName().c_str());
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
    });
}
