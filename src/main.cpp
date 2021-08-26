#include <iostream>

#include <Engine/Core.h>
#include <Engine/Window.h>
#include <Log.h>
#include <Rendering/CommandBuffer.h>

int main() {
    Snow::Log::init();
    SNOW_CORE_TRACE("Look! It started snowing!");

    Snow::Engine::Window window;
    Snow::Rendering::CommandBuffer buffer;

    buffer.clearRenderTarget(true, true, glm::vec4(0.45f, 0.33f, 0.45f, 1.0f));

    while (true) {
        window.update();
        buffer.execute();
    }

    return 0;
}
