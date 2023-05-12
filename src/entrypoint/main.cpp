#include "../App.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"

int main() {
    App app(580, 560, "Maple Engine");
    app.Launch();
    return 0;
}

#pragma clang diagnostic pop