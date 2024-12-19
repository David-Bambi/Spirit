#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <GLFW_C/Window.hpp>
#include <GLFW_C/GLFWObject.hpp>
#include <GF_C/GFWindow.hpp>

#include <GF_C/GFScene.hpp>
#include <GF_C/GFCamera.hpp>
#include <GF_C/GF2DScene.hpp>
#include <GF_Lab/Basic2DTest.hpp>

int main()
{

  GLFW_C::InitializeGlfw();

  Window* BasicWin = new GFWindow(800,
                                  800,
                                  "Goblin Factory",
                                  new GFColor(0.0f,0.0f,0.0f,1.0f));

  glfwSetInputMode(BasicWin->Get(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);  

  GFScene* scene = new Basic2DTest(BasicWin);

  scene->Build();
  GFCamera* cam = GFCamera::GetInstance(); 


  glEnable(GL_DEPTH_TEST);

  while(!glfwWindowShouldClose(BasicWin->Get()))
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
        // per-frame time logic
        // --------------------

      BasicWin->Draw();

      float currentFrame = static_cast<float>(glfwGetTime());
      scene->Draw(currentFrame);
      
      glfwSwapBuffers(BasicWin->Get());
      glfwPollEvents(); 
    }

  glfwTerminate();
    
  return 0;
}

