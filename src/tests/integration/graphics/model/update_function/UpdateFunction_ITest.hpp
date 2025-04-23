#ifndef UPDATEFUNCTION_ITESTS_HPP
#define UPDATEFUNCTION_ITESTS_HPP

#include <model/Model.hpp>

namespace UpdateFunction_ITest
{
    Model::Update Rotate = ([](Model& model) {
        model.get<Transform>()->Rotate(glm::vec3(0.0f, 0.0f, 1.0f));
    });

    Model::Update ScaleDown = ([](Model& model) {
        model.get<Transform>()->Scale(glm::vec3(0.98f, 0.98f, 0.0f));
    });

    Model::Update ScaleUp = ([](Model& model) {
        model.get<Transform>()->Scale(glm::vec3(1.02f, 1.02f, 0.0f));
    });

};

#endif