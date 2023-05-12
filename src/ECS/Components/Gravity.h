#ifndef MAPLEENGINE_GRAVITY_H
#define MAPLEENGINE_GRAVITY_H

#include "../Component.h"

class Gravity : public Component {
public:
    Gravity(Entity& owner, Entity& groundEntity, b2World& world) : Component(owner)
    {
        ground = groundEntity.body;
        m_World = &world;
    }
    void update(GLFWwindow* window, float deltaTime) override;
private:
    b2World* m_World;
    b2Body* ground;
};


#endif //MAPLEENGINE_GRAVITY_H
