#include "SphereRenderer.h"
#include <GLFW/glfw3.h>


SphereRenderer::SphereRenderer (Entity& owner, float radius) : Component(owner)
{
    m_Radius = radius;
    m_Quadric = gluNewQuadric();
}

void SphereRenderer::render() const
{
    const b2Body* body = getBody();

    glLoadIdentity();
    b2Vec2 ballPosition = body->GetPosition();
    glTranslatef (ballPosition.x, ballPosition.y, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    gluSphere(m_Quadric, m_Radius, 24, 24);
}