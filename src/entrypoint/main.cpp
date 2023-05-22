/** MapleEngine v0.0.1 pre-alpha
 *
 * Maple-Engine is a 2D game engine written in C++.
 * It uses OpenGL for rendering, Box2D for physics and also includes an entity-component-system.
 *
 * Version: 0.0.1
 * Author: Uljas Antero Lindell
 * GitHub: https://github.com/anteroul
 * @brief This is the main application where the window is initialized, as well as input, logging etc.
 */
#include "../App.h"
#include "../Log/msg.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

int main(int argc, char* argv[])
{
    int win_Width = 1280;
    int win_Height = 720;
    bool fullscreen = false;

    if (argc >= 3)
    {
        win_Width = std::stoi(argv[1]);
        win_Height = std::stoi(argv[2]);
        std::stoi(argv[3]);
    }

    try {
        std::string arg = argv[3];
        fullscreen = static_cast<bool>(std::stoi(arg));
    } catch (const std::exception &e) {
        printf("%s \bERROR: Invalid parameters. Windowed-mode enabled.\n", ERROR);
        win_Width = 600;
        win_Height = 580;
        fullscreen = false;
    }

    App app(win_Width, win_Height, "Maple Engine", fullscreen);
    app.Launch();
    return 0;
}

#pragma clang diagnostic pop