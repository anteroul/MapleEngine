#include "App.hh"
#include <cstdio>
#include <cstdlib>

App::App(unsigned int width, unsigned int height, char* windowTitle)
{
    glfwInit();
    glfwSetErrorCallback(ThrowError);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow((int)width, (int)height, windowTitle, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, HandleMouseMotion);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    //glewInit();
}

App::~App()
{
    glfwTerminate();
}

void App::Launch()
{
    while (!ApplicationShouldClose())
        RunApplication();
}

void App::RunApplication()
{
    printf("Application is running.\n");
    glfwPollEvents();
    HandleKeyInput(window);
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

bool App::ApplicationShouldClose()
{
    if (glfwWindowShouldClose(window))
        return true;

    return false;
}

void App::HandleKeyInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void App::HandleMouseMotion(GLFWwindow *window, double xPos, double yPos)
{
    auto mouseX = (float)xPos;
    auto mouseY = (float)yPos;
}

void App::ThrowError(int error, const char *description)
{
    fprintf(stderr, "ERROR: %s\n", description);
}