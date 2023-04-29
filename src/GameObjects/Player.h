#ifndef MAPLEENGINE_PLAYER_H
#define MAPLEENGINE_PLAYER_H

#include "../GameObject.h"

class Player : public GameObject {
public:
    Player(std::string name, glm::vec2 pos, glm::vec2 scale, glm::vec4 colour, bool setDynamic, bool applyPhysics, GLFWwindow* window);
    void UpdateLogic() override;
private:
    GLFWwindow* windowHandle;
};


#endif //MAPLEENGINE_PLAYER_H
