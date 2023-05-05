#ifndef MAPLEENGINE_WALLCOLLISION_H
#define MAPLEENGINE_WALLCOLLISION_H

#include "../Component.h"
#include "RecRenderer.h"

struct WallCollision : public Component {
    WallCollision(Entity& owner) : Component(owner) {};
    void initialize() override;
    RecRenderer *renderer;
};


#endif //MAPLEENGINE_WALLCOLLISION_H
