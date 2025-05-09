#ifndef SNCENE_HPP
#define SNCENE_HPP

#include <deque>
#include <memory>
#include <object/Object.hpp>
#include <model/Model.hpp>
#include <shader/ProgramShader.hpp>

class Scene : public Object
{
  public:
    void Init();
    void Render();
    void Clean();

  private:
    std::deque<std::shared_ptr<Model>> _models = {};
    std::shared_ptr<ProgramShader> _programShader = {};

    friend class SceneBuilder;
};

#endif