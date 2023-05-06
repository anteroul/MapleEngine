#ifndef MAPLEENGINE_ENTITY_H
#define MAPLEENGINE_ENTITY_H

#include <list>
#include <set>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Box2D/Box2D.h>

class Component;

class Entity {
public:
    Entity();
    ~Entity();

    void initialize();
    void update(GLFWwindow* window, float deltaTime);
    void render() const;

    b2AABB getAABB () const;

    // Component management
    template<typename T>
    T* getComponment() const {
        for (auto component : m_Components)
        {
            T* componentCast = dynamic_cast<T*>(component);
            if (componentCast != NULL)
                return componentCast;
        }

        return NULL;
    }
    void addComponent(Component* component);

    // Entity registration
    void setName(const std::string& name);
    const std::string& getName() const;
    void addTag(const std::string& tag);
    void removeTag(const std::string& tag);

    b2Body* body;
private:
    std::string m_Name;
    std::set<std::string> m_Tags;
    std::list<Component*> m_Components;
};


#endif //MAPLEENGINE_ENTITY_H
