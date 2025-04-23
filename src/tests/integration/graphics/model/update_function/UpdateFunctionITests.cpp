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
#include <UpdateFunction_ITest.hpp>


void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test update function");
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
                                   .WithUpdate(UpdateFunction_ITest::Rotate)
                                   .Build();

    Mod->ProcessComponents();
    bool changefunction = false;
    bool changescale = true;                            
    double lastTime = glfwGetTime();
    double currentTime;

    while (!glfwWindowShouldClose(Win))
    {
      processInput(Win);
      processRender(Win);
      Mod->Render(); 
     
      currentTime = glfwGetTime();
      if (currentTime - lastTime >= 5.0)
      {
        changescale = !changescale;
        lastTime = currentTime;
      }
      if (changescale && changefunction)
        Mod->SetUpdate(UpdateFunction_ITest::ScaleDown);
      else if (!changescale && changefunction)
        Mod->SetUpdate(UpdateFunction_ITest::ScaleUp);
      else
        Mod->SetUpdate(UpdateFunction_ITest::Rotate);

    
      changefunction = !changefunction;
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