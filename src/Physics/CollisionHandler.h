#ifndef MAPLEENGINE_COLLISIONHANDLER_H
#define MAPLEENGINE_COLLISIONHANDLER_H

#include <functional>
#include <map>
#include <Box2D/Box2D.h>
#include "../ECS/Entity.h"

struct CollisionHandler : b2ContactListener {
    typedef std::function<void(Entity*, b2Contact*)> Handler;
    void handleCollision(b2Contact* contact, b2Body* body, b2Body* second);
    void BeginContact(b2Contact* contact) override;
    std::map<b2Body*, Handler> handlers;
};


#endif //MAPLEENGINE_COLLISIONHANDLER_H
