#include "Player.h"

Player::Player(std::string name, glm::vec2 pos, glm::vec2 scale, glm::vec4 colour, bool setDynamic, bool applyPhysics, GLFWwindow* window) : GameObject(name, pos, scale, colour, setDynamic, applyPhysics)
{
    windowHandle = window;
}

void Player::UpdateLogic()
{
    if (glfwGetKey(windowHandle, GLFW_KEY_RIGHT) == GLFW_KEY_DOWN)
        position.x++;
    if (glfwGetKey(windowHandle, GLFW_KEY_LEFT) == GLFW_KEY_DOWN)
        position.x--;
    if (glfwGetKey(windowHandle, GLFW_KEY_SPACE) == GLFW_PRESS)
        colour = {0, 255, 0, 255};
}