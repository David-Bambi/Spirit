#ifndef CAMERAUPDATEDEF_HPP
#define CAMERAUPDATEDEF_HPP

#include <camera/Camera.hpp>
#include <input/Input.hpp>
#include <input/Key.hpp>

namespace CUD
{
Camera::UpdateFct FreeMove = ([](Camera &camera) {
  if (Input::mousemov) {
    camera.MouseMovement(Input::xoffset, Input::yoffset);
    Input::mousemov = false;
  }

  if (Input::scrollback) {
    camera.Zoom(Input::ysboffset);
    Input::scrollback = false;
  }

  if (Input::Pressed(Key::W) && Input::Pressed(Key::MAJ))
    camera.MoveUp();
  else if (Input::Pressed(Key::W))
    camera.MoveForward();

  if (Input::Pressed(Key::S) && Input::Pressed(Key::MAJ))
    camera.MoveDown();
  else if (Input::Pressed(Key::S))
    camera.MoveBackward();

  if (Input::Pressed(Key::A))
    camera.MoveLeft();
  if (Input::Pressed(Key::D))
    camera.MoveRight();
});
}; // namespace CUD

#endif