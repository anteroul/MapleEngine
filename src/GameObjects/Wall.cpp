#include "Wall.h"

#include "../ECS/Components/RecRenderer.h"
#include "../ECS/Components/WallCollision.h"
#include "../Material.h"

Wall::Wall(b2World& world, b2Vec2 topLeft, b2Vec2 bottomRight)
{
    b2Vec2 extents = 1./2. * b2Abs(topLeft - bottomRight);
    b2Vec2 origin = 1./2. * (topLeft + bottomRight);

    // TODO: Move the creation of the b2Body into a component.
    body = createBoxBody (world, origin, extents);

    // TODO: Reorganize this too.
    body->SetUserData(this);

    auto *m = new Material("blink.vert", "blink.frag");
    addComponent(new RecRenderer(*this, b2Vec3(extents.x, extents.y, 0.5), m));
    addComponent(new WallCollision(*this));
}

b2Body* Wall::createBoxBody(b2World& world, b2Vec2 origin, b2Vec2 extents)
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position = origin;

    b2PolygonShape groundBox;
    groundBox.SetAsBox(extents.x, extents.y);

    b2Body* body = world.CreateBody(&groundBodyDef);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &groundBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.;
    fixtureDef.restitution = 1;

    body->CreateFixture(&fixtureDef);
    return body;
}