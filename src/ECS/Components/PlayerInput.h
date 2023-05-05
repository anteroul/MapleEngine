#ifndef MAPLEENGINE_PLAYERINPUT_H
#define MAPLEENGINE_PLAYERINPUT_H

#include "../../Game.h"
#include "../Component.h"

struct PlayerInput : public Component {
    PlayerInput(Entity &owner, float speed);
    void update(GLFWwindow* window, float deltaTime) override;
    float m_Speed;
};


#endif //MAPLEENGINE_PLAYERINPUT_H
