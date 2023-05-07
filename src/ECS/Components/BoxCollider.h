#ifndef MAPLEENGINE_BOXCOLLIDER_H
#define MAPLEENGINE_BOXCOLLIDER_H

#include "../Component.h"
#include "BoxRenderer.h"

class BoxCollider : public Component {
public:
    BoxCollider(Entity& owner, Entity& other);
    void initialize() override;
    void update(GLFWwindow* window, float deltaTime) override;
private:
    Entity* m_Other;
};


#endif //MAPLEENGINE_BOXCOLLIDER_H
