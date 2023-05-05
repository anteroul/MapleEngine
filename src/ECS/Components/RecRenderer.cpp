#include "RecRenderer.h"
#include "../../Geometry.h"

/*
RecRenderer::RecRenderer(Entity &owner, const b2Vec3 &extents, Material *material) : Component(owner)
{
    mesh = Geometry::uploadBox(extents);

    if (material)
        material->setUniform("blink_t", 2.);
}
*/

RecRenderer::RecRenderer(Entity &owner, const b2Vec3 &extents) : Component(owner)
{
    mesh = Geometry::uploadBox(extents);
}

RecRenderer::~RecRenderer ()
{
    delete material;
    delete mesh;
}

void RecRenderer::render() const
{
    const b2Body* body = getBody();
    const b2Vec2 position = body->GetPosition();

    /*
    if (material)
        material->apply();

    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5f);
    glColor3f(0.9f, 0.9f, 1.f);

    mesh->render();

    if (material)
        Material::deactivate();
    */

    glBegin(GL_QUADS);
    glColor3f(255.f, 0.f, 0.f);
    glVertex2f(position.x - 0.25f, position.y - 0.25f);
    glVertex2f(position.x - 0.25f, position.y + 0.25f);
    glVertex2f(position.x + 0.25f, position.y + 0.25f);
    glVertex2f(position.x + 0.25f, position.y - 0.25f);
    glEnd();
}

void RecRenderer::update(GLFWwindow* window, float deltaTime)
{

}
