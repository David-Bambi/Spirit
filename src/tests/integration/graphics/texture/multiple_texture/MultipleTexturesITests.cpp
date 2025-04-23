#include <color/ColorDef.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <model/Mesh.hpp>
#include <model/MeshBuilder.hpp>
#include <model/MeshDef.hpp>
#include <shader_program/ShaderProg.hpp>
#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <texture/TextureBuilder.hpp>
#include <memory>
#include <stb_image/stb_image.h>
#include <iostream>
#include <filesystem>

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test multiple texture");
  uglad::GladInit();

  {
    ShaderProg SP = ShaderProg("./shader/basic.vs",
                               "./shader/basic.fs");

  
    SP.Use();

    MeshBuilder& B = MeshBuilder::GetInstance();

    std::unique_ptr<Mesh> M = B.WithVertices(MeshDef::RectangleV)
                               .WithIndexs(MeshDef::RectangleI)
                               .WithTextureCoord(MeshDef::RectangleT)
                               .WithTexture(TextureBuilder::GetInstance().WithPath("./texture/wood.jpg").Build())
                               .WithTexture(TextureBuilder::GetInstance().WithPath("./texture/rockwall.jpg").Build())
                               .WithTexture(TextureBuilder::GetInstance().WithPath("./texture/awesomeface.png").Build())
                               .WithShader(SP.Id())
                               .Build();
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