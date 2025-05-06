#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>
#include <shader/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <memory>
void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test triangle couleur");
  uglad::GladInit();

  {
    ShaderProg SP = ShaderProg("./shader/color.vs",
                               "./shader/color.fs");

    MeshBuilder& B = MeshBuilder::GetInstance();

    std::unique_ptr<Mesh> M = B.WithVertices(VerticesDef::TriangleV)
                               .WithColor({Color::Red, 
                                           Color::Cyan, 
                                           Color::Yellow}).Build();
    M->Setup(); 

    while (!glfwWindowShouldClose(Win))
    {
      processInput(Win);
      processRender(Win);
      SP.Use();
      M->Render(); 
     
      glfwSwapBuffers(Win);
      glfwPollEvents();
    }     
  }

  glfwTerminate();
  return 0;
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void processRender(GLFWwindow* win)
{
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT );
}