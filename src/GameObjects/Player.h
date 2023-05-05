#ifndef MAPLEENGINE_PLAYER_H
#define MAPLEENGINE_PLAYER_H

#include "../ECS/Entity.h"

class Player : public Entity {
public:
    Player() = default;
    Player(b2World& world, float width);
    ~Player();
    static float getHeight() { return 0.25f; }
private:
    b2Body* createBoxBody(b2World& world, b2Vec2 origin, b2Vec2 extents);
};


#endif //MAPLEENGINE_PLAYER_H
