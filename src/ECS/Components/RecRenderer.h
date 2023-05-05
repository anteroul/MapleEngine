#ifndef MAPLEENGINE_RECRENDERER_H
#define MAPLEENGINE_RECRENDERER_H

#include "../Component.h"
#include "../../Material.h"
#include "../../Physics/Mesh.h"

#include <GLFW/glfw3.h>

struct RecRenderer : public Component {
    Material *material;
    Mesh *mesh;
    bool blink;
    double blinkStart;

    RecRenderer (Entity& owner, const b2Vec3& extents, Material *material = nullptr);
    ~RecRenderer();

    void update(float deltaTime) override;
    void render() const override;

    void startBlinkAt(b2Vec2 position);
};


#endif //MAPLEENGINE_RECRENDERER_H
