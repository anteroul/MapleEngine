#ifndef MAPLEENGINE_SCENE_H
#define MAPLEENGINE_SCENE_H

#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>
#include <glm/vec2.hpp>
#include <GLFW/glfw3.h>

namespace DisplayManager {

    int GetMonitorCount()
    {
        Display* display = XOpenDisplay(nullptr);
        if (!display) {
            // Handle display opening error
            return 0;
        }

        XRRScreenResources* screenResources = XRRGetScreenResources(display, DefaultRootWindow(display));

        int monitorCount = screenResources->noutput;

        XCloseDisplay(display);
        XRRFreeScreenResources(screenResources);

        return monitorCount;
    }

    void scaleWindowSize(GLFWwindow* win, int x, int y)
    {
        glfwSetWindowSize(win, x, y);
    }

}

#endif //MAPLEENGINE_SCENE_H