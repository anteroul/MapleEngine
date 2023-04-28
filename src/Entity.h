#ifndef MAPLEENGINE_ENTITY_H
#define MAPLEENGINE_ENTITY_H

#include "constants/msg.h"
#include "Scene.h"
#include "Components.h"
#include <iostream>
#include <string>
#include <vector>

class Scene;

class Entity {
public:
    Entity() = default;
    Entity(Entity* entity, Scene* scene);
    Entity(const Entity& other) = default;

    template<typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
        T& Component = _SceneHandle->entities.emplace<T>(_EntityHandle, std::forward<Args>(args)...);
        std::cout << INFO << "Component added.\n";
        return Component;
    }

    template<typename T>
    T& GetComponent()
    {
        T* Component = std::cref(_SceneHandle->entities);
        for (auto & i : components)
            if (i == Component)
                return i;

        std::cout << WARNING << "Component not found!\n";
        return nullptr;
    }

    template<typename T>
    T& RemoveComponent()
    {
        T& Component = std::cref(_SceneHandle->entities);
        for (auto i = 0; i < components.size(); ++i)
        {
            if (components.at(i) == Component)
            {
                components.erase(components.cbegin() + i);
                std::cout << INFO << "Component deleted.\n";
                break;
            }
        }

        std::cout << WARNING << "WARNING: Component not found\n";
    }

    bool operator == (const Entity& other) const
    {
        return _EntityHandle == other._EntityHandle && _SceneHandle == other._SceneHandle;
    }

    bool operator != (const Entity& other) const
    {
        return !(*this == other);
    }
private:
    std::vector<Component*> components;
    Entity* _EntityHandle = nullptr;
    Scene* _SceneHandle = nullptr;
};


#endif //MAPLEENGINE_ENTITY_H
