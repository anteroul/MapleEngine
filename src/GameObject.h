#ifndef MAPLEENGINE_GAMEOBJECT_H
#define MAPLEENGINE_GAMEOBJECT_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <vector>
#include <memory>

class GameObject {
public:
    GameObject(std::string name, glm::vec2 pos, glm::vec2 _scale, glm::vec4 _colour, bool setDynamic, bool applyPhysics);
    ~GameObject();
    void UpdateData(std::shared_ptr<std::vector<GameObject>> data);
    void Update();
    void Render() const;
    std::string tagName;
protected:
    virtual void UpdateLogic();
    bool CheckCollision(GameObject* other);
    void UpdatePhysics();
    glm::vec2 position{};
    glm::vec2 scale{};
    glm::vec4 colour{};
    bool hasCollider = false;
    bool hasRigidBody = false;
    std::shared_ptr<std::vector<GameObject>> sceneData;
};


#endif //MAPLEENGINE_GAMEOBJECT_H
