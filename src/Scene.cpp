#include "Scene.h"

Scene::Scene() = default;

Scene::~Scene() = default;

Entity Scene::CreateEntity(const std::string &name)
{
    Entity entity;
    entity.AddComponent<IDComponent>(entityIndex);
    entity.AddComponent<TagComponent>(name);
    entityIndex++;
}

void Scene::DestroyEntity(Entity entity)
{
    for (auto i = 0; i < entities.size(); ++i)
        if (entities.at(i) == &entity)
            entities.erase(entities.cbegin() + i);
}

void Scene::UpdateScene()
{

}

void Scene::RenderScene()
{

}
