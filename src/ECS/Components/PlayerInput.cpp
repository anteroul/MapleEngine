#include "PlayerInput.h"
#include <cstdio>

PlayerInput::PlayerInput(Entity &owner, float speed) : Component(owner)
{
    m_Speed = speed;
}

void PlayerInput::update(GLFWwindow* window, float deltaTime)
{
    b2Body* body = getBody();

    if (body == nullptr)
        return;

    b2Vec2 desiredVelocity = b2Vec2_zero;

    if (glfwGetKey(window, GLFW_KEY_LEFT)) {
        desiredVelocity = b2Vec2(-m_Speed, 0.f);
        printf("Left key down!\n");
    } else if (glfwGetKey(window, GLFW_KEY_RIGHT)) {
        desiredVelocity = b2Vec2( m_Speed, 0.f);
        printf("Right key down!\n");
    }

    body->SetLinearVelocity(desiredVelocity);
    b2Vec2 gameSize = Game::getSize();
    b2AABB aabb = getEntity().getAABB();
    b2Vec2 position = body->GetPosition();

    if (aabb.lowerBound.x <= 0.f)
    {
        position.x -= aabb.lowerBound.x;
        body->SetTransform(position, body->GetAngle());
    } else if (aabb.upperBound.x >= gameSize.x) {
        position.x -= (aabb.upperBound.x - gameSize.x);
        body->SetTransform(position, body->GetAngle());
    }
}