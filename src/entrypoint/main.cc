#include "../App.hh"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

int main() {
    App app(1280, 720, "Maple Engine");
    app.Launch();
    return 0;
}

#pragma clang diagnostic pop