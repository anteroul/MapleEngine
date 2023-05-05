#ifndef MAPLEENGINE_MESH_H
#define MAPLEENGINE_MESH_H

#include "../../3rd_party/glad/include/glad/glad.h"

class Geometry;

class Mesh {
public:
    void render() const;
protected:
    int vertices;
    GLuint indexBufferID, vertexBufferID;
    friend class Geometry;
};


#endif //MAPLEENGINE_MESH_H
