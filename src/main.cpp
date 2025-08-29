#include <iostream>

#include "core/Window.h"
#include "core/Input.h"
#include "core/Shader.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

int main()
{

    Window window(1080, 784, "MineClone");


    Shader shader("shaders/vertex.glsl", "shaders/fragment.glsl");

    float vertices[] = {
        0.0f, 0.5f, 0.0f //top
        -0.5f, -0.5f, 0.0f, //Bottom Left
        0.5f, -0.5f, 0.0f // Bottom Right
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);


    /* Loop until the user closes the window */
    while (!window.shouldClose())
    {
        window.pollEvents();

        window.eventHandler(); // Handles frequent keypresses like movement keys

        window.clearScreen(); // Clear the scren
        
        
        shader.use();
        /* Render here */
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        window.swapBuffers();

        Input::update();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    return 0;
}
