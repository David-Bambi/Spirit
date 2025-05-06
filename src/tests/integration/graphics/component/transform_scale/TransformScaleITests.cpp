#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <shader/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test transform scale");
  uglad::GladInit();

  {
    ShaderProg SP = ShaderProg("./shader/transform.vs",
                               "./shader/transform.fs");

    MeshBuilder B = MeshBuilder();
    std::unique_ptr<Mesh> M = B.WithShader(SP.Id())
                               .WithVertices(VerticesDef::RectangleV)
                               .WithIndexs(VerticesDef::RectangleI)
                               .WithColor({Color::Red, 
                                           Color::Cyan, 
                                           Color::Yellow,
                                           Color::Blue}).Build();
    M->Setup(); 

    ModelBuilder& MB = ModelBuilder::GetInstance();
    std::unique_ptr<Model> Mod = MB.WithMesh(std::move(M))
                                   .WithScale({0.5f, 0.5f, 0.0f}).Build();

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