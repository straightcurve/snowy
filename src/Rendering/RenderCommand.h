//
// Created by tony on 8/26/21.
//

#ifndef SNOWY_RENDERCOMMAND_H
#define SNOWY_RENDERCOMMAND_H

namespace Snow::Rendering {
    class RenderCommand {
    public:
        virtual void execute() = 0;
    };
}

#endif //SNOWY_RENDERCOMMAND_H
