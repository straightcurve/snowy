//
// Created by tony on 8/26/21.
//

#ifndef SNOWY_CLEARRENDERTARGETCOMMAND_H
#define SNOWY_CLEARRENDERTARGETCOMMAND_H

#include <pch.h>
#include <Rendering/RenderCommand.h>

namespace Snow::Rendering::Commands {
    class ClearRenderTargetCommand : public Snow::Rendering::RenderCommand {
    public:
        bool clearDepth;
        bool clearColor;
        glm::vec4 color;
        float depth;

        ClearRenderTargetCommand(bool _clearDepth, bool _clearColor, glm::vec4 _color, float _depth);

        void execute() override;
    };
}

#endif //SNOWY_CLEARRENDERTARGETCOMMAND_H
