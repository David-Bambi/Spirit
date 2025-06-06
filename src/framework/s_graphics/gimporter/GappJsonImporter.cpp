#include <gimporter/GJsonImporter.hpp>

#include <fstream>
#include <gapp/GappBuilder.hpp>
#include <gapp/GAppSetting.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <tsl/robin_set.h>

using json = nlohmann::json;

namespace GappImporter
{
    bool ParseSetting(const json& data, GAppSetting& setting /*out*/);
    bool ParseDefaultScene(const json& data, GID_t& default_scene /*out*/);
    bool ParseScenes(const json& data, tsl::robin_set<GID_t>& scenes /*out*/);
};


std::shared_ptr<Gapp> GJsonImporter::ImportGapp(std::string name)
{
    std::ifstream File("res/gapp/"+name+".json");
    if (!File.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier JSON.\n";
        return nullptr;
    }

    json Data = json::parse(File);

    GAppSetting Setting = {};
    if (not GappImporter::ParseSetting(Data, Setting))
        return nullptr;

    GID_t SceneAtStart = -1;
    if (not GappImporter::ParseDefaultScene(Data, SceneAtStart))
        return nullptr;

    tsl::robin_set<GID_t> Scenes = {};
     if (not GappImporter::ParseScenes(Data, Scenes))
         return nullptr;

    std::shared_ptr<Gapp> Gapp = GappBuilder::GetInstance().WithSetting(Setting)
                                                           .WithDefaultScene(SceneAtStart)  
                                                           .WithScenes(Scenes)               
                                                           .BuildShared();

    return Gapp;
}

bool GappImporter::ParseSetting(const json& data, GAppSetting& setting)
{
    const auto& SettingJson = data["setting"];

    try
    {
        if (!SettingJson.contains("APP_NAME")) 
            throw std::runtime_error("Key 'APP_NAME' missing in 'setting'");
        else
            setting.APP_NAME = SettingJson["APP_NAME"];

        if (!SettingJson.contains("SCREEN_WIDTH")) 
            throw std::runtime_error("Key 'SCREEN_WIDTH' missing in 'setting'");
        else
            setting.SCREEN_WIDTH = SettingJson["SCREEN_WIDTH"];

        if (!SettingJson.contains("SCREEN_HEIGHT")) 
            throw std::runtime_error("Key 'SCREEN_HEIGHT' missing in 'setting'");
        else
            setting.SCREEN_HEIGHT = SettingJson["SCREEN_HEIGHT"]; 

        if (!SettingJson.contains("ENABLE_CURSOR")) 
            throw std::runtime_error("Key 'ENABLE_CURSOR' missing in 'setting'");
        else
            setting.ENABLE_CURSOR = SettingJson["ENABLE_CURSOR"]; 

        if (!SettingJson.contains("ENABLE_DEPTH_TEST")) 
            throw std::runtime_error("Key 'ENABLE_DEPTH_TEST' missing in 'setting'");
        else
            setting.ENABLE_DEPTH_TEST = SettingJson["ENABLE_DEPTH_TEST"]; 
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Exception JSON : " << e.what() << std::endl;
        return false;
    }
    
    return true;
}

bool GappImporter::ParseScenes(const json& data, tsl::robin_set<GID_t>& scenes /*out*/)
{
    try
    {
        if (!data.contains("scenes")) 
            throw std::runtime_error("Key 'scenes' missing");

        const auto& ScenesJson = data["scenes"];
        
        if (ScenesJson.empty())
            return true;
        
        for (const auto& scene : ScenesJson)
        {
            if (scene.empty())
                throw std::runtime_error("Scene name cannot be empty");

            GID_t gid = UGID::Get(scene);
            scenes.insert(gid);
        }
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Exception JSON : " << e.what() << std::endl;
        return false;
    }
    
    return true;
}

bool GappImporter::ParseDefaultScene(const json& data, GID_t& default_scene /*out*/)
{
    try
    {
        if (!data.contains("default_scene")) 
            throw std::runtime_error("Key 'default_scene' missing");

        const std::string& DefaultSceneJson = data["default_scene"];
        
        if (DefaultSceneJson.empty())
            return true;;

        default_scene = UGID::Get(DefaultSceneJson);
    }
    catch (const nlohmann::json::exception& e)
    {
        std::cerr << "Exception JSON : " << e.what() << std::endl;
        return false;
    }
    
    return true;
}