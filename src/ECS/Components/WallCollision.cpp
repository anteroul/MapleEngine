#include "WallCollision.h"

void WallCollision::initialize() {
    renderer = getComponent<RecRenderer>();

    Physics& physics = Game::getInstance().getPhysics();
    physics.collisionHandler(this, [this](Entity *collidedWith, b2Contact *contact)
    {
        printf("ZOMG COLLISION %s!\n", collidedWith->getName().c_str());
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        renderer->startBlinkAt(worldManifold.points[0]);
    });
}
