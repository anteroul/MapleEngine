#include "App.hh"
#include "constants/msg.h"
#include <cstdio>
#include <cstdlib>

App::App(unsigned int width, unsigned int height, char* windowTitle)
{
    glfwInit();
    glfwSetErrorCallback(ThrowError);

    if (!glfwInit())
        ThrowError(EXIT_FAILURE, "Unable to initialize GLFW.");
    else
        printf("%s \bSUCCESS: \t GLFW initialized successfully.\n", SUCCESS);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow((int)width, (int)height, windowTitle, nullptr, nullptr);

    if (!window)
        ThrowError(EXIT_FAILURE, "Failed to create OpenGL context window.");
    else
        printf("%s \bSUCCESS: \t Window created with a resolution of %u x %u.\n", SUCCESS, width, height);

    glfwMakeContextCurrent(window);
    glfwSetCursorPosCallback(window, HandleMouseMotion);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    //glewInit();

    //if (!glewInit())
    //    printf("%s \bERROR: \t Unable to initialize GLEW!\n", ERROR);
}

App::~App()
{
    glfwTerminate();
}

void App::Launch()
{
    printf("%s \bINFO: \t Application is now running!\n", INFO);
    InitGame();
    while (!ApplicationShouldClose())
        RunApplication();
}

void App::InitGame()
{
    gameObjects = std::make_shared<std::vector<GameObject>>();
    auto rigidBody = GameObject("Green", {-0.8f, 0.3f}, {0.1f, 0.2f}, {0, 255, 0, 255}, true, true);
    gameObjects->emplace_back(rigidBody);
    auto floor = GameObject("Ground", {0.f, -0.5f}, {2.f, 0.2f}, {8, 8, 8, 255}, true, false);
    gameObjects->emplace_back(floor);
}

void App::RunApplication()
{
    Update();
    Render();
}

bool App::ApplicationShouldClose()
{
    if (glfwWindowShouldClose(window))
        return true;

    return false;
}

void App::Update()
{
    glfwPollEvents();
    HandleKeyInput(window);
    HandleMouseMotion(window, 0, 0);

    for (auto & gameObject : *gameObjects)
    {
        gameObject.UpdateData(gameObjects);
        gameObject.Update();
    }
}

void App::Render()
{
    glClearColor(0.f, 0.f, 0.f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto & gameObject : *gameObjects)
        gameObject.Render();

    glfwSwapBuffers(window);
}

void App::HandleKeyInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void App::HandleMouseMotion(GLFWwindow *window, double xPos, double yPos)
{
    int width, height;
    glfwGetCursorPos(window, &xPos, &yPos);
    glfwGetWindowSize(window, &width, &height);

    if (xPos > 0 && xPos <= width && yPos > 0 && yPos <= height)
    {
        printf("\r%s \bMouseX: %d, MouseY: %d", WARNING, (int) xPos, (int) yPos);
        fflush(stdout);
    }
}

void App::ThrowError(int error, const char *description)
{
    fprintf(stderr, "ERROR %d: \t %s\n", error, description);
    exit(error);
}
