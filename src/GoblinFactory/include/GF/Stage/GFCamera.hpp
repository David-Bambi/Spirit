/** @class GFCamera
 *  @author David Boivin 
 * Class for the camera in graphic mode**/

#ifndef GFCAMERA_HPP
#define GFCAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Camera
{
    enum class Type
    {
        Othogonal,
        Projection
    };
}

class GFCamera
{
private :
    

protected :

public :
    GFCamera(unsigned int winWidth, unsigned int winHeight);

    glm::mat4 ViewMatrix();
    glm::mat4 ProjectionMatrix();

    glm::vec3 _Pos;
    glm::vec3 _Front;
    glm::vec3 _Up;

    Camera::Type CameraType;
    unsigned int _winWidth;
    unsigned int _winHeight;

    bool _isFirstMouse = true;
    float _lastX;
    float _lastY;

    float _yaw = -90.0f;
    float _pitch = 0;
    float _fov = 45.0f;

    float _speed = 0.1f;
    float _deltatime = 0.0f;
    float _lastframe = 0.0f;

    float _near = -100;
    float _far = 100;
    void MoveForward();
    void MoveBackward();
    void MoveLeft();
    void MoveRight();
    void ModifyFront();
    void Turn(double xpos, double ypos);
};

#endif