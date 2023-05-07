#ifndef MAPLEENGINE_BOXCOLLIDER_H
#define MAPLEENGINE_BOXCOLLIDER_H

#include "../Component.h"
#include "BoxRenderer.h"

struct BoxCollider : public Component {
    BoxCollider(Entity& owner) : Component(owner) {};
    void initialize() override;
};


#endif //MAPLEENGINE_BOXCOLLIDER_H
