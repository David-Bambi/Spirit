#include <GF_C/GFScene.hpp>

void GFScene::Draw(float frame)
{
  GFCamera* cam = GFCamera::GetInstance();

  cam->_deltatime = frame - cam->_lastframe;
  cam->_lastframe = frame;



  for (std::map<unsigned int, std::vector<GFDraw_I*>>::iterator it = DrawingObjects.begin();
       it != DrawingObjects.end(); ++it)
    {    
      glm::mat4 V = glm::lookAt(cam->Position(), 
                                cam->Position() + cam->Target(), 
                                cam->Up()); 
                                  
      glUseProgram(it->first);

      unsigned int viewLoc = glGetUniformLocation(it->first, "view");
      glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(V));

      glm::mat4 P =  glm::perspective(glm::radians(cam->fov), 800.0f / 800.0f, 0.1f, 100.0f);
      unsigned int projectionLoc = glGetUniformLocation(it->first, "projection");
      glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(P));

      glm::vec3 lightcolor = glm::vec3(1.0f, 1.0f, 1.0f);
      unsigned int lightColorLoc = glGetUniformLocation(it->first, "lightColor");
      glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightcolor));

      unsigned int viewPosLoc = glGetUniformLocation(it->first, "viewPos");
      glUniform3fv(viewPosLoc, 1, glm::value_ptr(cam->Position()));

      unsigned int lightPosLoc = glGetUniformLocation(it->first, "lightPos");
      glUniform3fv(lightPosLoc, 1, glm::value_ptr(this->lightpos));

      std::vector<GFDraw_I*> objToRender = it->second;
      
      for (std::vector<GFDraw_I*>::iterator it = objToRender.begin();
       it != objToRender.end(); ++it)
         {
           (*it)->Draw();
         }
    }
}
