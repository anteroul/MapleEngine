#include "Physics.h"

#include <utility>

Physics::Physics() : world(b2Vec2_zero), accumulator(0.f)
{
    world.SetContactListener(&handler);
}

void Physics::update(float deltaTime)
{
    accumulator += deltaTime;

    while (accumulator >= getStepSize())
    {
        accumulator -= getStepSize();
        world.Step(getStepSize(), getVelocitySolverIterations(), getPositionSolverIterations());
    }
}

void Physics::collisionHandler(Component *component, CollisionHandler::Handler function)
{
    handler.handlers[component->getBody()] = std::move(function);
}

