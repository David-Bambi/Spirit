#ifndef GAPPDEF_HPP
#define GAPPDEF_HPP

#include <gapp/Gapp.hpp>
#include <gapp/GappBuilder.hpp>
#include <def/SceneDef.hpp>
#include <memory>

namespace GappDef
{
// const std::unique_ptr<Gapp> EmptyWindowGapp =
//     GappBuilder::GetInstance().WithAppSetting({"Empty Window", 1280, 960}).BuildUnique();

// const std::unique_ptr<Gapp> ShapeGapp = GappBuilder::GetInstance()
//                                             .WithAppSetting({"Shape", 680, 400, false, true})
//                                             .WithScene(SceneDef::ShapeScene)
//                                             .BuildUnique();
}; // namespace GappDef

#endif