#ifndef SNCENE_HPP
#define SNCENE_HPP

#include <deque>
#include <memory>
#include <object/Object.hpp>
#include <model/Model.hpp>
#include <shader/ProgramShader.hpp>
#include <camera/Camera.hpp>
#include <tsl/robin_map.h>

class Scene : public GraphicObject
{
  public:
    void Init();
    void Render();
    void Clean();

  private:
    std::deque<std::shared_ptr<Model>> _models = {};
    tsl::robin_map<std::shared_ptr<ProgramShader>, std::deque<std::shared_ptr<Model>>>
        _modelsByProgramShader = {};
    std::shared_ptr<Camera> _camera = {};
    friend class SceneBuilder;
};

#endif