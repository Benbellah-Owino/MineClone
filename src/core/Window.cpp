#include "Window.h"
#include "Input.h"
#include "iostream"


Window::Window(int width, int height, const std::string &title)
{
    /* Initialize the library */
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        m_window = nullptr;
        return;
    }

    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (!m_window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);
    glfwSetWindowUserPointer(m_window, this);

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(m_window);
        glfwTerminate();
        m_window = nullptr;
    }


    // Initialize input with our window
    Input::init(m_window);
}

Window::~Window()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
}

void Window::pollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();
}

void Window::swapBuffers()
{
    /* Swap front and back buffers */
    if (m_window)
        glfwSwapBuffers(m_window);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

bool Window::isKeyPressed(int key) const
{
    return glfwGetKey(m_window, key) == GLFW_PRESS;
}

void Window::clearScreen()
{
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}


// Handles frequent key presses. Checks for them per frame eg movement
void Window::eventHandler()
{

    if (Input::isKeyDown(GLFW_KEY_W))
    {
        // Move forward
        std::cout<< "W pressed this frame" << std::endl;
    }
    if ( Input::isKeyDown(GLFW_KEY_S))
    {
        // Move backward
        std::cout<< "S pressed this frame" << std::endl;
    }

    if (Input::isKeyDown(GLFW_KEY_A))
    {
        // Move left
        std::cout<< "A pressed this frame" << std::endl;
    }

    if (Input::isKeyDown(GLFW_KEY_D))
    {
        // Move right
        std::cout<< "D pressed this frame" << std::endl;
    }

    if(Input::isKeyPressed(GLFW_KEY_SPACE)){
        std::cout<< "Space is being held" << std::endl;
    }

    if(Input::isKeyPressed(GLFW_KEY_ESCAPE)){
        std::cout<< "Escape released -> quitting" << std::endl;
        Window* win = static_cast<Window*>(glfwGetWindowUserPointer(m_window));
        glfwSetWindowShouldClose(m_window, true);
    }
}




