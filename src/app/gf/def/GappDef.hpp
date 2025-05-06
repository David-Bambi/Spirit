#ifndef GAPPDEF_HPP
#define GAPPDEF_HPP

#include <gapp/Gapp.hpp>
#include <gapp/GappBuilder.hpp>
#include <memory>

namespace GappDef
{
const std::unique_ptr<Gapp> EmptyWindowGapp =
    GappBuilder::GetInstance().WithAppSetting({"Empty Window", 1280, 960}).Build();

};

#endif