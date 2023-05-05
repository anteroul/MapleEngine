#ifndef MAPLEENGINE_COLLISIONHANDLER_H
#define MAPLEENGINE_COLLISIONHANDLER_H

#include <functional>
#include <map>
#include <Box2D/Box2D.h>
#include "../Core/Entity.h"

struct CollisionHandler : b2ContactListener {
    typedef std::function<void(Entity*, b2Contact*)> Handler;
    std::map<b2Body*, Handler> handlers;
    void handleCollision(b2Contact* contact, b2Body* body, b2Body* second);
    virtual void BeginContact(b2Contact* contact) override;
};


#endif //MAPLEENGINE_COLLISIONHANDLER_H
