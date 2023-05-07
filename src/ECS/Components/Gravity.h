#ifndef MAPLEENGINE_GRAVITY_H
#define MAPLEENGINE_GRAVITY_H

#include "../Component.h"

class Gravity : public Component {
public:
    Gravity(Entity& owner, b2World& world) : Component(owner)
    {
        m_World = &world;
    }
    void update(GLFWwindow* window, float deltaTime) override;
private:
    b2World* m_World;
};


#endif //MAPLEENGINE_GRAVITY_H
