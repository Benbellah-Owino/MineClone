#include <iostream>

#include "core/Window.h"
#include "core/Input.h"
#include "core/Shader.h"
#include "core/Camera.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

// create global camera
Camera camera(glm::vec3(0.0f, 0.f, 3.0f));

// deltaTime handling
float deltaTime = 0.0f;
float lastFrame = 0.0f;

void processInput(Window &window);

int main()
{
    Window window(1080, 784, "MineClone");

    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    float vertices[] = {
        // Position         Colors
        0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // top
        -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  // Bottom Right
    };

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute (location = 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Position attribute (location = 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    /* Loop until the user closes the window */
    while (!window.shouldClose())
    {

        float currentFrame = glfwGetTime();
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        window.pollEvents();

        window.eventHandler(); // Handles frequent keypresses like movement keys

        window.clearScreen(); // Clear the scren

        processInput(window);

        shader.use();
        /* Render here */
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)window.getWidth() / (float)window.getHeight(),
                                                0.1f, 100.0f);

        glm::mat4 view = camera.getViewMatrix();

        shader.setMat4s("projection", projection);
        shader.setMat4s("view", view);

        // If you want a model matrix (object transform)
        glm::mat4 model = glm::mat4(1.0f);
        shader.setMat4s("model", model);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffers();

        Input::update();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    return 0;
}

void processInput(Window &window)
{
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;

    if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window.getNativeWindow(), GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(RIGHT, deltaTime);
}