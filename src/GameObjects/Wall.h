#ifndef MAPLEENGINE_WALL_H
#define MAPLEENGINE_WALL_H

#include "../Game.h"

class Wall : public Entity {
public:
    Wall(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);
private:
    b2Body* createBoxBody(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight);
};

#endif //MAPLEENGINE_WALL_H
