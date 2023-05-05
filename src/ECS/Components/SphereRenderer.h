#ifndef MAPLEENGINE_SPHERERENDERER_H
#define MAPLEENGINE_SPHERERENDERER_H

#include "../Component.h"
#include <Box2D/Box2D.h>
#include <GL/glu.h>

class SphereRenderer : public Component {
public:
    SphereRenderer(Entity& owner, float radius);
    void render() const override;
    float m_Radius;
private:
    GLUquadric *m_Quadric;
};


#endif //MAPLEENGINE_SPHERERENDERER_H
