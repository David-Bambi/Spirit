#include <gapp/GappBuilder.hpp>

GappBuilder& GappBuilder::GetInstance()
{
    static GappBuilder instance;
    return instance;
}

GappBuilder& GappBuilder::WithAppSetting(const AppSetting& setting)
{
    _obj->_setting = setting;
    return *this;
}
