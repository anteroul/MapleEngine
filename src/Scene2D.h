#ifndef MAPLEENGINE_SCENE2D_H
#define MAPLEENGINE_SCENE2D_H

#include <string>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <box2d/box2d.h>
#include <memory>
#include "GameObject.h"

class Scene2D {
public:
    Scene2D();
    ~Scene2D();
    void UpdateScene(float xPos, float yPos);
    void RenderScene();
private:
    glm::vec2 ToVec2(float x, float y);
    std::vector<GameObject> gameObjects;
    //std::unique_ptr<GameObject> cursor;
    b2Vec2 gravity;
    b2World* world;
};


#endif //MAPLEENGINE_SCENE2D_H
