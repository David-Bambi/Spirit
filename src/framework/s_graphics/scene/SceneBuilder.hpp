#ifndef SCENEBUILDER_HPP
#define SCENEBUILDER_HPP

#include <scene/Scene.hpp>

/**
 * @brief Helper class to build Scene
 *
 */
class SceneBuilder : public Builder<Scene>
{
  public:
    static SceneBuilder& GetInstance();
    SceneBuilder& WithModel(std::unique_ptr<Model> model);
};

#endif