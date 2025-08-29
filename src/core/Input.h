#pragma once
#include <unordered_map>
#include "GLFW/glfw3.h"

class Input{
    public:
        static void init(GLFWwindow* window);
        static bool isKeyPressed(int key);
        static bool isKeyDown(int key);
        static bool isKeyReleased(int key);

        static void update(); // Call once per frame

    private: 
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
        
        static std::unordered_map<int, bool> keys;
        static std::unordered_map<int, bool> keysDown;
        static std::unordered_map<int, bool> keysUp;

};