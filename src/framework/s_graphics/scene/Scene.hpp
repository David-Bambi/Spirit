#ifndef SNCENE_HPP
#define SNCENE_HPP

#include <deque>
#include <memory>
#include <model/Model.hpp>

class Scene
{
  public:
    Scene() = default;
    Scene(const Scene&) = default;
    Scene(Scene&&) noexcept = default;
    Scene& operator=(const Scene&) = default;
    Scene& operator=(Scene&&) = default;
    virtual ~Scene() = default;

    void Render();

  private:
    std::deque<std::unique_ptr<Model>> _models = {};

    friend class SceneBuilder;
};

#endif