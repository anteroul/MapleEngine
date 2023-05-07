#ifndef MAPLEENGINE_BOXCOLLIDER_H
#define MAPLEENGINE_BOXCOLLIDER_H

#include "../Component.h"
#include "BoxRenderer.h"

class BoxCollider : public Component {
public:
    BoxCollider(Entity& owner) : Component(owner) {};
    void initialize() override;
private:
    BoxRenderer *renderer;
};


#endif //MAPLEENGINE_BOXCOLLIDER_H
