#pragma once
#include <string>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Window{
    public:
        Window(int width, int height, const std::string& title);
        ~Window();

        void pollEvents();
        void swapBuffers();
        void clearScreen();
        void eventHandler();
        bool shouldClose() const;
        bool isKeyPressed(int key) const;

        GLFWwindow* getNativeWindow() const {return m_window;};

    private:
        GLFWwindow* m_window;
};
