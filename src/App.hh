#pragma once

#ifndef MAPLEENGINE_APP_HH
#define MAPLEENGINE_APP_HH

#include "Scene2D.h"
#include "../3rd_party/glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

class App {
public:
    App(unsigned int width, unsigned int height, char* windowTitle);
    ~App();
    void Launch();
private:
    void RunApplication();
    void Update();
    void Render();
    bool ApplicationShouldClose();
    void HandleKeyInput(GLFWwindow* window);
    static void HandleMouseMotion(GLFWwindow* window, double xPos, double yPos);
    static void ThrowError(int error, const char* description);
    GLFWwindow* window;
    Scene2D* example2DScene;
};


#endif //MAPLEENGINE_APP_HH
