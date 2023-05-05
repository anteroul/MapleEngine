#ifndef MAPLEENGINE_GEOMETRY_H
#define MAPLEENGINE_GEOMETRY_H

#include "Physics/Mesh.h"
#include <Box2D/Box2D.h>

struct Geometry {
    static Mesh* uploadBox(b2Vec3 extens);
private:
    static unsigned short* createTrianglesForQuad (unsigned short topLeft, unsigned short bottomLeft, unsigned short bottomRight, unsigned short topRight, unsigned short* indices);
};


#endif //MAPLEENGINE_GEOMETRY_H
