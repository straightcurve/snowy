#include <iostream>

#include <Engine/Core.h>
#include <Engine/Window.h>
#include <Log.h>

int main() {
    Snow::Log::init();
    SNOW_CORE_TRACE("Look! It started snowing!");

    Snow::Engine::Window window;

    while (true) {
        window.update();
    }

    return 0;
}
