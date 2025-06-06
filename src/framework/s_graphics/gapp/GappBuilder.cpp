#include <gapp/GappBuilder.hpp>

GappBuilder& GappBuilder::GetInstance()
{
    static GappBuilder instance;
    return instance;
}

GappBuilder& GappBuilder::WithSetting(const GAppSetting& setting)
{
    _obj->_setting = setting;
    return *this;
}

GappBuilder& GappBuilder::WithDefaultScene(const GID_t& default_scene)
{
    _obj->_default_scene = default_scene;
    return *this;
}

GappBuilder& GappBuilder::WithScenes(const tsl::robin_set<GID_t>& scenes)
{
    _obj->_scenes = scenes;
    return *this;
}
