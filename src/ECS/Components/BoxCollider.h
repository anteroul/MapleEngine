#ifndef MAPLEENGINE_BOXCOLLIDER_H
#define MAPLEENGINE_BOXCOLLIDER_H

#include "../Component.h"
#include "BoxRenderer.h"
#include <vector>

class BoxCollider : public Component {
public:
    BoxCollider(Entity& owner, Entity& ignore, b2World& world);
    void update(GLFWwindow* window, float deltaTime) override;
private:
    Entity* self;
    Entity* ignored;
    int bodyCount;
    std::vector<b2Body*> bodies;
};


#endif //MAPLEENGINE_BOXCOLLIDER_H
