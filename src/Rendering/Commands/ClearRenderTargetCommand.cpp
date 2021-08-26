//
// Created by tony on 8/26/21.
//

#include <glad/glad.h>
#include <Rendering/Commands/ClearRenderTargetCommand.h>

namespace Snow::Rendering::Commands {
    ClearRenderTargetCommand::ClearRenderTargetCommand(
            bool _clearDepth,
            bool _clearColor, glm::vec4 _color,
            float _depth
    ) : clearDepth(_clearDepth),
        clearColor(_clearColor),
        color(_color),
        depth(_depth) {
    }

    void ClearRenderTargetCommand::execute() {
        uint32_t bits = 0;

        if (clearColor) {
            bits |= GL_COLOR_BUFFER_BIT;

            glClearColor(
                    color
                            .
                                    r * color
                            .a,
                    color.
                            g * color
                            .a,
                    color.
                            b * color
                            .a,
                    color.a
            );
        }

        if (clearDepth) {
            glClearDepth(depth);
            bits |= GL_DEPTH_BUFFER_BIT;
        }

        glClear(bits);
    }
}