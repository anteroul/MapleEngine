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

    if (glfwGetKey(window, GLFW_KEY_LEFT))
        body->SetTransform(b2Vec2(body->GetPosition().x - m_Speed, body->GetPosition().y), body->GetAngle());
    if (glfwGetKey(window, GLFW_KEY_RIGHT))
        body->SetTransform(b2Vec2(body->GetPosition().x + m_Speed, body->GetPosition().y), body->GetAngle());
    if (glfwGetKey(window, GLFW_KEY_UP))
        body->SetTransform(b2Vec2(body->GetPosition().x, body->GetPosition().y + m_Speed), body->GetAngle());
    if (glfwGetKey(window, GLFW_KEY_DOWN))
        body->SetTransform(b2Vec2(body->GetPosition().x, body->GetPosition().y - m_Speed), body->GetAngle());

}