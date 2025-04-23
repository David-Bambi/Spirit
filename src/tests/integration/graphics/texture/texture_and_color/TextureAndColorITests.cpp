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

void processInput(GLFWwindow *window);
void processRender(GLFWwindow *window);

int main()
{
  uglfw::InitializeGlfw();
  GLFWwindow* Win = uglfw::CreateWinContext(800, 600, "Test multiple texture with color");
  uglad::GladInit();

  {
    ShaderProg SP = ShaderProg("./shader/texcol.vs",
                               "./shader/texcol.fs");

  
    MeshBuilder& B = MeshBuilder::GetInstance();
    TextureBuilder& TB = TextureBuilder::GetInstance();

    std::unique_ptr<Mesh> M = B.WithVertices(MeshDef::RectangleV)
                               .WithIndexs(MeshDef::RectangleI)
                               .WithTextureCoord(MeshDef::RectangleT)
                               .WithColor({Color::Blue,
                                           Color::Cyan,
                                           Color::Magenta,
                                           Color::Yellow})
                               .WithTexture(TB.WithPath("./texture/wood.jpg").Build())
                               .WithTexture(TB.WithPath("./texture/rockwall.jpg").Build())
                               .WithTexture(TB.WithPath("./texture/awesomeface.png")
                                              .WithImagLoadSetting({true /*flip vertically*/}).Build())
                               .WithShader(SP.Id())
                               .Build();
    M->Setup(); 

    
    while (!glfwWindowShouldClose(Win))
    {
      processInput(Win);
      processRender(Win);

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