#include "Entity.h"

#include "Component.h"
#include "../Game.h"

Entity::Entity() : m_Name("")
{}

Entity::~Entity()
{
    for (auto component : m_Components)
        delete component;
}

void Entity::initialize()
{
    for (auto component : m_Components)
        component->initialize();
}

void Entity::update(float delta)
{
    for (auto component : m_Components)
        component->update(delta);
}

void Entity::render() const
{
    for (auto component : m_Components)
        component->render();
}

void Entity::addComponent(Component *component)
{
    m_Components.push_back(component);
}

void Entity::setName(const std::string& name)
{
    Game& game = Game::getInstance();
    if (name.length() > 0) {
        if (m_Name.length() > 0)
            game.removeEntityName(this, m_Name);

        game.setEntityName(this, name);
    } else if (m_Name.length() > 0) {
        game.removeEntityName(this, m_Name);
    }

    m_Name = name;
}

const std::string& Entity::getName() const
{
    return m_Name;
}

void Entity::addTag(const std::string& tag)
{
    if (m_Tags.count(tag) > 0)
        return;

    m_Tags.insert(tag);
    Game::getInstance().addEntityTag(this, tag);
}

void Entity::removeTag(const std::string& tag)
{
    auto tagIterator = m_Tags.find(tag);
    if (tagIterator == m_Tags.end())
        return;

    m_Tags.erase(tagIterator);
    Game::getInstance().removeEntityTag(this, tag);
}

b2AABB Entity::getAABB () const
{
    b2AABB aabb;
    aabb.lowerBound = b2Vec2(FLT_MAX,FLT_MAX);
    aabb.upperBound = b2Vec2(-FLT_MAX,-FLT_MAX);

    for (b2Fixture* fixture = body->GetFixtureList(); fixture != NULL; fixture = fixture->GetNext ()) {
        aabb.Combine(aabb, fixture->GetAABB(0));
    }

    return aabb;
}
