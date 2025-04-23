#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <model/Mesh.hpp>
#include <model/MeshBuilder.hpp>
#include <model/MeshDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <shader_program/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test transform rotate");
  uglad::GladInit();

  {
    ShaderProg SP = ShaderProg("./shader/transform.vs",
                               "./shader/transform.fs");

    MeshBuilder B = MeshBuilder();
    std::unique_ptr<Mesh> M = B.WithShader(SP.Id())
                               .WithVertices(MeshDef::RectangleV)
                               .WithIndexs(MeshDef::RectangleI)
                               .WithColor({Color::Red, 
                                           Color::Cyan, 
                                           Color::Yellow,
                                           Color::Blue}).Build();
    M->Setup(); 

    ModelBuilder& MB = ModelBuilder::GetInstance();
    std::unique_ptr<Model> Mod = MB.WithMesh(std::move(M))
                                   .WithRotation({45.0f, 0.0f, 10.0f}).Build();

    Mod->ProcessComponents();

    while (!glfwWindowShouldClose(Win))
    {
      processInput(Win);
      processRender(Win);
      Mod->Render(); 
     
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