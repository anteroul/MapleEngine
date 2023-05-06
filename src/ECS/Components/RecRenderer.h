#ifndef MAPLEENGINE_RECRENDERER_H
#define MAPLEENGINE_RECRENDERER_H

#include "../Component.h"
#include "../../Material.h"
#include "../../Physics/Mesh.h"

class RecRenderer : public Component {
public:
    RecRenderer(Entity& owner, const b2Vec3& extents, Material *material = nullptr);
    ~RecRenderer();
    void update(GLFWwindow* window, float deltaTime) override;
    void render() const override;
    void startBlinkAt(b2Vec2 position);
private:
    Material *material;
    Mesh *mesh;
    bool blink;
    double blinkStart;
};


#endif //MAPLEENGINE_RECRENDERER_H
