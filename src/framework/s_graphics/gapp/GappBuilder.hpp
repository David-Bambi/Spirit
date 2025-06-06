#ifndef GAPPBUILDER_HPP
#define GAPPBUILDER_HPP

#include <builder/Builder.hpp>

#include <gapp/Gapp.hpp>
#include <gobject/UGID.hpp>
#include <tsl/robin_set.h>

/**
 * @brief Helper class to build graphics application
 *
 */
class GappBuilder : public Builder<Gapp>
{
  public:
    static GappBuilder& GetInstance();

    GappBuilder& WithSetting(const GAppSetting& setting);
    GappBuilder& WithDefaultScene(const GID_t& default_scene);
    GappBuilder& WithScenes(const tsl::robin_set<GID_t>& scenes);
};

#endif