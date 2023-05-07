#include "BoxRenderer.h"
#include "../../Geometry.h"

BoxRenderer::BoxRenderer(Entity &owner, glm::vec2 size, glm::vec3 colour) : Component(owner)
{
    m_Size = size;
    m_Colour = colour;
}

BoxRenderer::~BoxRenderer() = default;

void BoxRenderer::render() const
{
    const b2Body* body = getBody();
    const b2Vec2 position = body->GetPosition();

    glLoadIdentity();
    glBegin(GL_QUADS);
    glTranslatef(position.x, position.y, 0.f);
    glColor3f(m_Colour.r, m_Colour.g, m_Colour.b);
    glVertex2f(position.x - m_Size.x, position.y - m_Size.y);
    glVertex2f(position.x - m_Size.x, position.y + m_Size.y);
    glVertex2f(position.x + m_Size.x, position.y + m_Size.y);
    glVertex2f(position.x + m_Size.x, position.y - m_Size.y);
    glEnd();
    glFlush();
}