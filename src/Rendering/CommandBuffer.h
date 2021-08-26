//
// Created by tony on 8/26/21.
//

#ifndef SNOWY_COMMANDBUFFER_H
#define SNOWY_COMMANDBUFFER_H

#include <pch.h>
#include <Rendering/RenderCommand.h>
#include <Rendering/Commands/ClearRenderTargetCommand.h>

namespace Snow::Rendering {

    class CommandBuffer {
    private:
        std::vector<std::unique_ptr<Snow::Rendering::RenderCommand>> buffer;
    public:
        std::string name;

        void clearRenderTarget(bool clearDepth, bool clearColor, glm::vec4 color, float depth = 1.f) {
            buffer.push_back(std::make_unique<Snow::Rendering::Commands::ClearRenderTargetCommand>(clearDepth, clearColor, color, depth));
        }

        void clear() {
            buffer.clear();
        }

        /**
         * FIXME: This should probably be in another class
         */
        void execute() {
            for (auto &cmd : buffer)
                cmd->execute();
        }
    };
}

#endif //SNOWY_COMMANDBUFFER_H
