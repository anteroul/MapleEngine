#ifndef MAPLEENGINE_GAME_H
#define MAPLEENGINE_GAME_H

#include "Core/Entity.h"

#include <list>
#include <map>

class Game {
public:
    static Game& getInstance();
    static b2Vec2 getSize() { return b2Vec2(10., 7.5); }

    void initialize();
    void update(float delta);
    void render();

    void setEntityName(Entity* entity, const std::string& name);
    void removeEntityName(Entity* entity, const std::string& name);
    Entity* getEntityWithName(const std::string& name) const;

    void addEntityTag(Entity* entity, const std::string& tag);
    void removeEntityTag(Entity* entity, const std::string& tag);
    std::list<Entity*> getEntitiesWithTag(const std::string& tag) const;
    Entity* getEntityWithTag(const std::string& tag) const;
private:
    static Game gameInstance;

    std::list<Entity*> entities;
    std::map<std::string, Entity*> names;
    std::map<std::string, std::list<Entity*>> tags;

    Game();
};

#endif //MAPLEENGINE_GAME_H
