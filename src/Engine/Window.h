//
// Created by tony on 8/26/21.
//

#ifndef SNOWY_WINDOW_H
#define SNOWY_WINDOW_H

#include <Engine/Core.h>
#include <GLFW/glfw3.h>

namespace Snow::Engine {
    class Window {
    private:
        struct Callbacks {
            std::function<void()> closed;
        };
        Callbacks m_callbacks;
        GLFWwindow *m_window = nullptr;
        bool m_vsync = true;

        void update_viewport_size();

    public:
        Window();

        ~Window();

        inline bool get_vsync() {
            return m_vsync;
        }

        inline GLFWwindow *get_window() {
            return m_window;
        }

        void set_vsync(bool enabled);

        void on_window_closed(std::function<void()>);

        void update();
    };
}

#endif //SNOWY_WINDOW_H
