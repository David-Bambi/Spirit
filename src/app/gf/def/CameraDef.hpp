#ifndef CAMERADEF_HPP
#define CAMERADEF_HPP

#include <camera/Camera.hpp>
#include <camera/CameraBuilder.hpp>
#include <camera/CameraUpdateDef.hpp>
#include <camera/ProjectionDef.hpp>

namespace CameraDef
{
std::shared_ptr<Camera> Cam01 = CameraBuilder::GetInstance()
                                    .WithPosition({0.0f, 1.0f, 3.0f})
                                    .WithFront({0.0f, 0.0f, -1.0f})
                                    .Up({0.0f, 1.0f, 0.0f})
                                    .WithProjectionType(Projection_t::PERSPECTIVE)
                                    .WithUpdate(CUD::FreeMove)
                                    .WithMouvementSettings(0.10f, 2.5f)
                                    .BuildShared();
}

#endif