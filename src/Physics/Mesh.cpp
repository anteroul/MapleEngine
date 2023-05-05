#include "Mesh.h"
#include <Box2D/Box2D.h>

void Mesh::render() const
{
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(b2Vec3), nullptr);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    glDrawElements(GL_TRIANGLES, vertices, GL_UNSIGNED_SHORT, nullptr);
}