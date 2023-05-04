#ifndef MAPLEENGINE_GAMEOBJECT_H
#define MAPLEENGINE_GAMEOBJECT_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

class GameObject {
public:
    GameObject(std::string name, glm::vec2 pos, glm::vec2 _scale, glm::vec4 _colour, bool setDynamic, bool applyPhysics);
    ~GameObject();
    std::string GetTagName();
    void MoveTo(glm::vec2 pos);
    void Render() const;
private:
    glm::vec2 position{};
    glm::vec2 scale{};
    glm::vec4 colour{};
    std::string tagName;
    bool hasCollider = false;
    bool hasRigidBody = false;
};


#endif //MAPLEENGINE_GAMEOBJECT_H
