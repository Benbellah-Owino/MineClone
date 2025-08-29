#include <iostream>

#include "core/Window.h"
#include "core/Input.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

int main()
{

    Window window(1080, 784, "MineClone");

    // Example glm usage
    glm::vec3 pos(1.0f, 2.0f, 3.0f);
    glm::vec3 dir(0.0f, 0.0f, -1.0f);
    glm::vec3 result = pos + dir;

    std::cout << "Result: "
              << result.x << ", "
              << result.y << ", "
              << result.z << std::endl;

    /* Loop until the user closes the window */
    while (!window.shouldClose())
    {
        window.pollEvents();

        window.eventHandler(); // Handles frequent keypresses like movement keys

        window.clearScreen(); // Clear the scren
        /* Render here */
        window.swapBuffers();

        Input::update();
    }

    return 0;
}
