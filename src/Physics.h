#ifndef MAPLEENGINE_PHYSICS_H
#define MAPLEENGINE_PHYSICS_H

#include "box2d/box2d.h"
#include "ECS/Component.h"
#include <map>
#include <list>
#include <vector>

class Physics {
public:
    Physics();
    void update(Entity* entity, float deltaTime);
    /// \return reference to game world
    b2World& getWorld() { return world; }
    static float getForce(float mass, float speed, float deltaTime);
    static float getAcceleration(float speed, float deltaTime);
private:
    static float getStepSize() { return 1.f/60.f; }
    static int getVelocitySolverIterations() { return 8.f; }
    static int getPositionSolverIterations() { return 3.f; }
    b2World world;
    double accumulator;
};


#endif //MAPLEENGINE_PHYSICS_H
