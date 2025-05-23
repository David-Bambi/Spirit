#ifndef SCENEBUILDER_HPP
#define SCENEBUILDER_HPP

#include <builder/Builder.hpp>
#include <memory>
#include <model/Model.hpp>
#include <scene/Scene.hpp>
#include <shader/ProgramShader.hpp>

/**
 * @brief Helper class to build Scene
 *
 */
class SceneBuilder : public Builder<Scene>
{
  public:
    static SceneBuilder& GetInstance();

    SceneBuilder& WithModel(const std::shared_ptr<Model>& model,
                            const std::shared_ptr<ProgramShader>& programShader);
    SceneBuilder& WithCamera(const std::shared_ptr<Camera>& camera);
};

#endif