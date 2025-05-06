#ifndef GAPPBUILDER_HPP
#define GAPPBUILDER_HPP

#include <builder/Builder.hpp>

#include <gapp/Gapp.hpp>

/**
 * @brief Helper class to build graphics application
 *
 */
class GappBuilder : public Builder<Gapp>
{
  public:
    static GappBuilder& GetInstance();

    GappBuilder& WithAppSetting(const AppSetting& setting);
};

#endif