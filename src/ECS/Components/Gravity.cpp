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

        if (body->GetPosition().y < ground->GetPosition().y + 0.3f)
            body->SetTransform(b2Vec2(position.x, position.y + 0.001f), angle);
        else
            body->SetTransform(b2Vec2(position.x, position.y - 0.001f), angle);
    }
}
