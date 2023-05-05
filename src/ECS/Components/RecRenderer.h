#ifndef MAPLEENGINE_RECRENDERER_H
#define MAPLEENGINE_RECRENDERER_H

#include "../Component.h"
#include "../../Material.h"
#include "../../Physics/Mesh.h"

struct RecRenderer : public Component {
    Material *material;
    Mesh *mesh;
    bool blink;
    double blinkStart;

    RecRenderer(Entity& owner, const b2Vec3 &extents);
    //RecRenderer (Entity& owner, const b2Vec3& extents, Material *material = nullptr);
    ~RecRenderer();

    void update(GLFWwindow* window, float deltaTime) override;
    void render() const override;
};


#endif //MAPLEENGINE_RECRENDERER_H
