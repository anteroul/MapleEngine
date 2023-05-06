#ifndef MAPLEENGINE_RIGIDBODY_H
#define MAPLEENGINE_RIGIDBODY_H

#include "../Component.h"
#include <Box2D/Box2D.h>

class RigidBody : public Component {
public:
    RigidBody(Entity &owner, const b2Vec3 &extents);
    void update(GLFWwindow* window, float deltaTime) override;
};


#endif //MAPLEENGINE_RIGIDBODY_H
