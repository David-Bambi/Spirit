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

GappBuilder& GappBuilder::WithScene(const std::shared_ptr<Scene>& scene)
{
    _obj->_scene = scene;
    return *this;
}