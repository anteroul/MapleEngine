#ifndef MAPLEENGINE_SCENE_H
#define MAPLEENGINE_SCENE_H

#include "Entity.h"

class Entity;

struct Scene {
    Scene();
    ~Scene();
    Entity CreateEntity(const std::string& name);
    void DestroyEntity(Entity entity);
    void UpdateScene();
    void RenderScene();
    std::vector<Entity*> entities;
    unsigned entityIndex = 0;
};


#endif //MAPLEENGINE_SCENE_H
