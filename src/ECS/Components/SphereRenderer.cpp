#include "SphereRenderer.h"

SphereRenderer::SphereRenderer(Entity& owner, float radius, glm::vec3 colour) : Component(owner)
{
    m_Radius = radius;
    m_Quadric = gluNewQuadric();
    m_Colour = colour;
}

void SphereRenderer::render() const
{
    const b2Body* body = getBody();

    glLoadIdentity();
    b2Vec2 ballPosition = body->GetPosition();
    glTranslatef(ballPosition.x, ballPosition.y, 0.f);
    glColor3f(m_Colour.r, m_Colour.g, m_Colour.b);
    gluSphere(m_Quadric, m_Radius, 24, 24);
    glFlush();
}