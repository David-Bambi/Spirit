#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <camera/Camera.hpp>
#include <camera/CameraBuilder.hpp>
#include <mesh/Mesh.hpp>
#include <mesh/MeshBuilder.hpp>
#include <mesh/VerticesDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <shader/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <memory>
#include <time/Time.hpp>
#include <camera/ProjectionDef.hpp>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test camera perspective");
  uglad::GladInit();

  glEnable(GL_DEPTH_TEST);

  {
    ShaderProg SP = ShaderProg("./shader/camera.vs",
                               "./shader/camera.fs");


    MeshBuilder& B = MeshBuilder::GetInstance();
    std::unique_ptr<Mesh> M = B.WithShader(SP.Id())
                               .WithVertices(VerticesDef::CubeV)
                               .WithColor({Color::Red, 
                                           Color::Red,
                                           Color::Red, 
                                           Color::Red,
                                           Color::Green,
                                           Color::Green,
                                           Color::Green,
                                           Color::Green})
                               .WithIndexs(VerticesDef::CubeI)
                               .Build();
    M->Setup(); 

    ModelBuilder& MB = ModelBuilder::GetInstance();
    std::unique_ptr<Model> Mod = MB.WithMesh(std::move(M))
                                   .WithScale({0.5f, 0.5f, 0.5f})
                                   .Build();
    Mod->ProcessComponents();

    CameraBuilder& CB = CameraBuilder::GetInstance();
    std::unique_ptr<Camera> Cam = CB.WithPosition({-1.0f, 1.0f, 3.0f})
                                    .WithFront({0.0f, 0.0f, -1.0f})
                                    .WithPojectionType(Projection_t::PERSPECTIVE)
                                    .WithShader(SP.Id())
                                    .Build();

    while (!glfwWindowShouldClose(Win))
    {
      Time::Update();

      processInput(Win);
      processRender(Win);
      SP.Use();
      Cam->Update();
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}