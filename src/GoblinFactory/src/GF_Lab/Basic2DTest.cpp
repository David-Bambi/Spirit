  #include <GF_Lab/Basic2DTest.hpp>

Basic2DTest::Basic2DTest(Window* window)
{
  this->_window = window;
  glfwSetKeyCallback (this->_window->Get(), Basic2DTest::OnKeyEvent);
  glfwSetCursorPosCallback(this->_window->Get(), Basic2DTest::OnMousePosEvent);
  glfwSetScrollCallback(this->_window->Get(), Basic2DTest::OnScrollEvent);
}
  
void Basic2DTest::Build()
{
  GF2DScene::Build();
  GFTexture tex = GFTexture("textures/wall.jpg");

  // First row from right to left
  GF2DTriangle* rec1 = new GF2DTriangle(this->_shaderId,
                                          Color::Blue,
                                          tex.Id());

  GF2DRectangle* rec2 = new GF2DRectangle(this->_shaderId,
                                           Color::Green,
                                           tex.Id());

  GF2DCircle* rec3 = new GF2DCircle(this->_shaderId,
                                    1.0f,
                                    Color::Red,
                                    tex.Id());

  GF2DCube* cube1 = new GF2DCube(this->_shaderId,
                                 Color::Green,
                                 tex.Id());

  GF2DCube* light = new GF2DCube(this->_shaderId,
                                  Color::Black);
  
  rec1->T = glm::translate(rec1->T, glm::vec3(-0.5f, 0.5f, 0.0f));
  rec1->T = glm::scale(rec1->T, glm::vec3(0.2, 0.2, 0.2));

  rec2->T = glm::translate(rec2->T, glm::vec3(0.0f, 0.5f, 0.0f));
  rec2->T = glm::scale(rec2->T, glm::vec3(0.2, 0.2, 0.2));

  rec3->T = glm::translate(rec3->T, glm::vec3(0.5f, 0.5f, 0.0f));
  rec3->T = glm::scale(rec3->T, glm::vec3(0.2, 0.2, 0.2));

  this->lightpos = glm::vec3(0.3f, 0.3f, -0.4f);
  light->T = glm::translate(light->T, this->lightpos);
  light->T = glm::scale(light->T, glm::vec3(0.3, 0.3, 0.3));

  cube1->T = glm::translate(cube1->T, glm::vec3(0.0f, 0.0f, 0.0f));
  //cube1->T = glm::rotate(cube1->T, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  cube1->T = glm::scale(cube1->T, glm::vec3(0.2, 0.2, 0.2));

  this->DrawingObjects[this->_shaderId].push_back(rec1);
  this->DrawingObjects[this->_shaderId].push_back(rec2);
  this->DrawingObjects[this->_shaderId].push_back(rec3);
  this->DrawingObjects[this->_shaderId].push_back(cube1);
  this->DrawingObjects[this->_shaderLightId].push_back(light);
}


void Basic2DTest::OnMousePosEvent(GLFWwindow* window, 
                                double xpos, 
                                double ypos)
{
GFCamera* cam = GFCamera::GetInstance();

  if (cam->firstMouse)
    {
        cam->lastX = xpos;
        cam->lastY = ypos;
        cam->firstMouse = false;
    }

float xoffset = xpos - cam->lastX;
float yoffset = cam->lastY - ypos; // reversed since y-coordinates range from bottom to top
cam->lastX = xpos;
cam->lastY = ypos;

const float sensitivity = 0.05f;
xoffset *= sensitivity;
yoffset *= sensitivity;

cam->yaw += xoffset;
cam->pitch += yoffset;

if(cam->pitch  > 89.0f)
  cam->pitch  =  89.0f;
if(cam->pitch < -89.0f)
  cam->pitch = -89.0f;


glm::vec3 direction;
direction.x = cos(glm::radians(cam->yaw)) * cos(glm::radians(cam->pitch));
direction.y = sin(glm::radians(cam->pitch));
direction.z = sin(glm::radians(cam->yaw)) * cos(glm::radians(cam->pitch));
cam->Target(glm::normalize(direction));

}

void Basic2DTest::OnKeyEvent(GLFWwindow* window,
                             int         key,
                             int         scancode,
                             int         action,
                             int         mods)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(window, true);

    GFCamera* cam = GFCamera::GetInstance();

   // cam->Speed(75.0f * cam->_deltatime);
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cam->MoveForward();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cam->MoveBackward();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cam->MoveLeft();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cam->MoveRight();
}

void Basic2DTest::OnScrollEvent(GLFWwindow* window, double xoffset, double yoffset)
{
  GFCamera* cam = GFCamera::GetInstance();
  cam->fov -= (float)yoffset;
  if (cam->fov < 1.0f)
      cam->fov = 1.0f;
  if (cam->fov > 45.0f)
      cam->fov = 45.0f; 
}