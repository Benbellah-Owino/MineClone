#include "Input.h"
#include <iostream>

std::unordered_map<int, bool> Input::keys;
std::unordered_map<int, bool> Input::keysDown;
std::unordered_map<int, bool> Input::keysUp;

void Input::init(GLFWwindow *window)
{
    glfwSetKeyCallback(window, keyCallback);
}

bool Input::isKeyPressed(int key)
{
    return keys[key];
}

bool Input::isKeyDown(int key)
{
    return keysDown[key];
}

bool Input::isKeyReleased(int key)
{
    return keysUp[key];
}

void Input::update()
{
     // reset keysDown and keysUp after each frame
    keysDown.clear();
    keysUp.clear();
}

void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    
    if (action == GLFW_PRESS)
    {
        keys[key] = true;
        keysDown[key] = true;
    }else if(action == GLFW_RELEASE){
        keys[key] = false;
        keysUp[key] = true;
    }
}

void Input::mouseCallback(GLFWwindow *window, double xpos, double ypos)
{
    // Use xpos, ypos for camera rotation
}