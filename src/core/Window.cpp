#include "Window.h"
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

    glfwSetKeyCallback(m_window, keyCallback);
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Load OpenGL functions with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(m_window);
        glfwTerminate();
        m_window = nullptr;
    }
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
    glClear(GL_COLOR_BUFFER_BIT);
}


// Handles frequent key presses. Checks for them per frame eg movement
void Window::eventHandler()
{

    if (isKeyPressed(GLFW_KEY_W))
    {
        // Move forward
        std::cout<< "^" << std::endl;
    }
    if ( isKeyPressed(GLFW_KEY_S))
    {
        // Move backward
        std::cout<< "|" << std::endl;
    }
    if (isKeyPressed(GLFW_KEY_A))
    {
        // Move left
        std::cout<< "<" << std::endl;
    }
    if (isKeyPressed(GLFW_KEY_W))
    {
        // Move right
        std::cout<< ">" << std::endl;
    }
}


// Handles rare key presses when they happen
void Window::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    Window* win = static_cast<Window*>(glfwGetWindowUserPointer(window));
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        // jump
    }

    // Example
    if(win){
        if(action == GLFW_PRESS){
            std::cout << "Key pressed: " << key << std::endl;
        }
    }
}

void Window::mouseCallback(GLFWwindow *window, double xpos, double ypos)
{
    // Use xpos, ypos for camera rotation
}
