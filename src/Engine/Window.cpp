//
// Created by tony on 8/26/21.
//

#include <Engine/Window.h>
#include <glad/glad.h>

namespace Snow::Engine {
    static bool s_glfw_initialized;
    static bool s_glad_initialized;

    Window::Window() {
        glfwSetErrorCallback([](int error, const char *description) {
            SNOW_CORE_ERROR("GLFW error %d: %s", error, description);
        });

        if (!s_glfw_initialized) {
            s_glfw_initialized = glfwInit();
            SNOW_CORE_ASSERT(s_glfw_initialized, "Failed to initialize GLFW..");
        }

        m_window = glfwCreateWindow(1280, 720, "Snow", nullptr, nullptr);
        SNOW_CORE_ASSERT(m_window != nullptr, "Unable to create GLFW window!");

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &m_callbacks);
        set_vsync(m_vsync);

        glfwSetWindowCloseCallback(m_window, [](auto window) {
            Callbacks &callbacks = *(Callbacks *) glfwGetWindowUserPointer(window);
            if (callbacks.closed != nullptr)
                callbacks.closed();
        });

        s_glad_initialized = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        if (!s_glad_initialized) {
            SNOW_CORE_ERROR("Failed to initialize glad..");
            glfwDestroyWindow(m_window);
            glfwTerminate();

            return;
        }

        update_viewport_size();
    }

    Window::~Window() {
        if (!s_glfw_initialized)
            return;

        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::set_vsync(bool enabled) {
        m_vsync = enabled;

        if (!s_glfw_initialized)
            return;

        glfwSwapInterval(enabled);
    }

    void Window::update() {
        SNOW_CORE_ASSERT(s_glfw_initialized, "Tried to update window before GLFW has been initialized!");

        glfwPollEvents();

        glfwSwapBuffers(m_window);

//        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w,
//                     clear_color.w);
//        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::on_window_closed(std::function<void()> callback) {
        m_callbacks.closed = std::move(callback);
    }

    /**
     * should only run when the window is
     * initialized and/or the window is resized
     */
    void Window::update_viewport_size() {
        SNOW_CORE_ASSERT(s_glfw_initialized, "Tried to update viewport size before GLFW has been initialized!");
        SNOW_CORE_ASSERT(s_glad_initialized, "Tried to update viewport size before graphics API has been initialized!");

        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
    }
}