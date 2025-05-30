#include <uglfw/uglfw.hpp>

/**
 * @brief
 *
 * @return true
 * @return false
 */
bool uglfw::InitializeGlfw()
{
    if (!glfwInit())
        return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

    return true;
}

/**
 * @brief
 *
 * @param height
 * @param width
 * @param title
 * @param monitor
 * @param share
 * @return GLFWwindow*
 */
GLFWwindow* uglfw::CreateWinContext(int height, int width, const char* title)
{
    GLFWwindow* winctx = glfwCreateWindow(height, width, title, nullptr, nullptr);
    if (winctx == nullptr)
    {
        std::cout << "Failed to create GLFW window\n";
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(winctx);
    return winctx;
}

/**
 * @brief
 *
 * @param WinCtx
 */
void uglfw::SetViewPortResizeable(GLFWwindow* winctx)
{
    auto resizefct = [](GLFWwindow* window, int width, int height)
    {
        if (window == nullptr)
            return;
        glViewport(0, 0, width, height);
    };
    glfwSetFramebufferSizeCallback(winctx, resizefct);
}
