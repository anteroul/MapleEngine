#include "Gravity.h"

void Gravity::update(GLFWwindow *window, float deltaTime)
{
    b2Body* body = getBody();
    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    for (int32 i = 0; i < 60; ++i)
    {
        m_World->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();
        //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
    body->SetTransform(b2Vec2(body->GetPosition().x, body->GetPosition().y - 0.01f), body->GetAngle());
}
