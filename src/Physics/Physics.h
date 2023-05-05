#ifndef MAPLEENGINE_PHYSICS_H
#define MAPLEENGINE_PHYSICS_H

#include <map>
#include <list>
#include <Box2D/Box2D.h>
#include "../ECS/Component.h"
#include "CollisionHandler.h"

class Physics {
public:
    Physics();
    void update(float deltaTime);

    b2World& getWorld() { return world; }

    float getStepSize() const { return 1.f/60.f; }
    int getVelocitySolverIterations() const { return 8.f; }
    int getPositionSolverIterations() const { return 3.f; }

    void collisionHandler(Component* component, CollisionHandler::Handler function);
private:
    b2World world;
    double accumulator;
    CollisionHandler handler;
};


#endif //MAPLEENGINE_PHYSICS_H
