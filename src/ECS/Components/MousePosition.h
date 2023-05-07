#ifndef MAPLEENGINE_MOUSEPOSITION_H
#define MAPLEENGINE_MOUSEPOSITION_H

#include "../Component.h"

class MousePosition : public Component {
public:
    MousePosition(Entity& owner);
    void update(GLFWwindow* window, float deltaTime) override;
private:
    b2Body* body;
};


#endif //MAPLEENGINE_MOUSEPOSITION_H
