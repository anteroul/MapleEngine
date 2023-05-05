#include "RecRenderer.h"
#include "../../Geometry.h"

RecRenderer::RecRenderer(Entity &owner, const b2Vec3 &extents, Material *material) : Component(owner), blink(false)
{
    mesh = Geometry::uploadBox(extents);

    if (material)
        material->setUniform("blink_t", 2.);
}

RecRenderer::~RecRenderer ()
{
    delete material;
    delete mesh;
}

void RecRenderer::render() const
{
    const b2Body* body = getBody();
    if (body == NULL) {
        // TODO: Log error.
        return;
    }

    if (material)
        material->apply();

    const b2Vec2 position = body->GetPosition();
    glLoadIdentity();
    glTranslatef(position.x, position.y, 0.5);
    glColor3f(0.9, 0.9, 1.0);

    mesh->render();

    if (material)
        Material::deactivate();
}

void RecRenderer::update(GLFWwindow* window, float deltaTime)
{
    // XXX: Ugh. This depends on a "correct" material being passed in.
    if (blink) {
        double timePassed = glfwGetTime() - blinkStart;
        material->setUniform("blink_t", timePassed);
        if (timePassed > 1.) {
            blink = false;
        }
    }
}

void RecRenderer::startBlinkAt(b2Vec2 position)
{
    if (material != NULL) {
        blink = true;
        printf("%f", position.y);
        material->setUniform("blink_y", position.y);
        blinkStart = glfwGetTime();
    }
}