#ifndef MAPLEENGINE_PLAYERINPUT_H
#define MAPLEENGINE_PLAYERINPUT_H

#include "../../Game.h"
#include "../Component.h"
#include <GLFW/glfw3.h>


struct PlayerInput : public Component {
    PlayerInput(Entity &owner, Entity &entity, float speed);
    void update(GLFWwindow* window, float deltaTime);
    float m_Speed;
};


#endif //MAPLEENGINE_PLAYERINPUT_H
