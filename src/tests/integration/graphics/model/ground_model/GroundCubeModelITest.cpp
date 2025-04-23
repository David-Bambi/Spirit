#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <camera/Camera.hpp>
#include <camera/CameraBuilder.hpp>
#include <model/Mesh.hpp>
#include <model/MeshBuilder.hpp>
#include <model/MeshDef.hpp>
#include <model/Model.hpp>
#include <model/ModelBuilder.hpp>
#include <shader_program/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <memory>
#include <input/Input.hpp>
#include <time/Time.hpp>
#include <camera/CameraUpdateDef.hpp>
#include <camera/ProjectionDef.hpp>
#include <Algo.hpp>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test camera movement");
  uglad::GladInit();
  glEnable(GL_DEPTH_TEST);
  Input::Window = Win;
  
  glfwSetCursorPosCallback(Win, Input::MouseCallback);
  glfwSetScrollCallback(Win, Input::MouseScrollCallback);

  uglfw::SCREEN_WIDTH = 800.0f;
  uglfw::SCREEN_HEIGHT = 600.0f;

  glfwSetInputMode(Win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

  {
    ShaderProg SP = ShaderProg("./shader/camera.vs",
                               "./shader/camera.fs");


    MeshBuilder& B = MeshBuilder::GetInstance();

      std::vector<std::unique_ptr<Model>> ModVec;

    for (int i = 0; i<100 ; i++ )
    {
      for (int j = 0; j<100; j++)
      {

        double xnorm = ((j / 100.0f));
        double ynorm = ((i / 100.0f));

        double noise = ALGO::PerlinNoiseWithOctave(xnorm, ynorm, 2 /*frequency*/, 1.0 /*amplitude*/, 2 /*octave*/);

        int height = (int) (ALGO::Normalize(noise, -1.0, 1.0) * 10.0f);

        for (int z = 0; z<height; z++)
        {

          std::unique_ptr<Mesh> M = B.WithShader(SP.Id())
                                     .WithVertices(MeshDef::CubeV)
                                     .WithColor({Color::Red, 
                                      Color::Cyan,
                                      Color::Magenta,
                                      Color::Yellow,
                                      Color::Green,
                                      Color::Blue,
                                      Color::White,
                                      Color::Black})
                                     .WithIndexs(MeshDef::CubeI)
                                     .Build();
          M->Setup(); 
        

          ModelBuilder& MB = ModelBuilder::GetInstance();
          std::unique_ptr<Model> Mod = MB.WithMesh(std::move(M))
                                         .WithPosition(glm::vec3((float)i,  float(z), (float)j))
                                         .WithScale(glm::vec3{0.5f, 0.5f, 0.5f})
                                         .Build();
          Mod->ProcessComponents();



          ModVec.push_back(std::move(Mod));
        }
      }
    }

    std::cout << "ModVec size: " << ModVec.size() << std::endl;
     
    CameraBuilder& CB = CameraBuilder::GetInstance();
    std::unique_ptr<Camera> Cam = CB.WithPosition({-1.0f, 5.0f, -3.0f})
                                    .WithFront({0.0f, -1.0f, -1.0f})
                                    .Up({0.0f, 1.0f, 0.0f})
                                    .WithProjectionType(Projection_t::PERSPECTIVE)
                                    .WithShader(SP.Id())
                                    .WithUpdate(CUD::FreeMove)
                                    .WithMouvementSettings(0.10f, 2.5f)
                                    .Build();

    while (!glfwWindowShouldClose(Win))
    {
      Time::Update();

      processInput(Win);
      processRender(Win);

      SP.Use();
      Cam->Update();
      for (const auto& Mod : ModVec)
      {
        Mod->Render(); 
      }
     
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