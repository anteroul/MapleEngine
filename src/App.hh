#ifndef MAPLEENGINE_APP_HH
#define MAPLEENGINE_APP_HH

#include "GameObject.h"
#include "gameObjects/StaticObject.h"
#include <GLFW/glfw3.h>

class App {
public:
    App(unsigned int width, unsigned int height, char* windowTitle);
    ~App();
    void Launch();
private:
    void RunApplication();
    void InitGame();
    void Update();
    void Render();
    bool ApplicationShouldClose();
    static void HandleKeyInput(GLFWwindow* window);
    static void HandleMouseMotion(GLFWwindow* window, double xPos, double yPos);
    static void ThrowError(int error, const char* description);
    GLFWwindow* window;
    std::shared_ptr<std::vector<GameObject>> gameObjects;
};


#endif //MAPLEENGINE_APP_HH
