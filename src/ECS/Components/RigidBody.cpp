#include "RigidBody.h"

RigidBody::RigidBody(Entity &owner, const b2Vec3 &extents) : Component(owner)
{
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.2f, 0.2f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3f;
    owner.body->CreateFixture(&fixtureDef);
}

void RigidBody::update(GLFWwindow *window, float deltaTime)
{
    Component::update(window, deltaTime);
}
