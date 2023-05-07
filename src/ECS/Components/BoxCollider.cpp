#include "BoxCollider.h"
#include "../../Game.h"

BoxCollider::BoxCollider(Entity& owner, Entity& other) : Component(owner)
{
    m_Other = &other;
}

void BoxCollider::initialize()
{
    Physics& physics = Game::getInstance().getPhysics();

    physics.collisionHandler(this, [this](Entity *collidedWith, b2Contact *contact)
    {
        b2Vec2 oldPosition = collidedWith->body->GetTransform().p;
        printf("%f, %f", oldPosition.x, oldPosition.y);
        printf("Collision detected %s!\n", collidedWith->getName().c_str());
        b2WorldManifold worldManifold;
        contact->GetWorldManifold(&worldManifold);
        collidedWith->body->SetTransform(oldPosition, this->getBody()->GetAngle());
    });
}

void BoxCollider::update(GLFWwindow *window, float deltaTime)
{
    b2Body* ground = getBody();
    b2Body* contact = m_Other->body;

    if (contact->GetPosition().y < ground->GetPosition().y + 0.3f)
        contact->SetTransform(b2Vec2(contact->GetPosition().x, contact->GetPosition().y + 0.01f), contact->GetAngle());

    Component::update(window, deltaTime);
}
