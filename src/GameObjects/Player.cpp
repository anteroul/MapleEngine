#include "Player.h"
#include "../Game.h"

#include "../ECS/Components/RecRenderer.h"
#include "../ECS/Components/PlayerInput.h"

#define PLAYER_SPEED 8.0f

Player::Player(b2World &world, float width)
{
    b2Vec2 extents = 1.f/2.f * b2Vec2(width, getHeight());
    b2Vec2 origin(Game::getSize().x / 2.f, getHeight() + 0.25f);

    // TODO: Move the creation of the b2Body into a component.
    body = createBoxBody (world, origin, extents);

    // TODO: Reorganize this too.
    body->SetUserData(this);

    addComponent(new RecRenderer(*this, b2Vec3(extents.x, extents.y, 0.5f)));
    addComponent(new PlayerInput(*this, PLAYER_SPEED));
}

Player::~Player() = default;

b2Body *Player::createBoxBody(b2World &world, b2Vec2 origin, b2Vec2 extents)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    bodyDef.position = origin;

    b2PolygonShape box;
    box.SetAsBox(extents.x, extents.y);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &box;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.f;

    b2Body* body = world.CreateBody(&bodyDef);
    body->CreateFixture(&fixtureDef);
    return body;
}


