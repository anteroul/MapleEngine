#pragma once

#ifndef MAPLEENGINE_APP_HH
#define MAPLEENGINE_APP_HH

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Game.h"

class App {
public:
    App(unsigned int width, unsigned int height, char* windowTitle);
    ~App();
    void Launch();
private:
    void RunApplication(Game& game);
    void Update(Game& game, double cTime);
    void Render(Game& game);
    bool ApplicationShouldClose();
    void HandleKeyInput(GLFWwindow* window);
    static void HandleMouseMotion(GLFWwindow* window, double xPos, double yPos);
    static void ThrowError(int error, const char* description);
    GLFWwindow* window;
};


#endif //MAPLEENGINE_APP_HH
