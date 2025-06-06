#include <catch2/catch_test_macros.hpp>
#include <gapp/Gapp.hpp>
#include <gapp/GappBuilder.hpp>
#include <gapp/GAppSetting.hpp>
#include <gobject/UGID.hpp>
#include <memory>
#include <tsl/robin_set.h>

TEST_CASE("GappBuildRawPtr", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    Gapp* G = GB.Build();
    
    REQUIRE(G != nullptr);
    delete G;
}

TEST_CASE("GappBuildUniquePtr", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    std::unique_ptr<Gapp> G = GB.BuildUnique();
    
    REQUIRE(G != nullptr);
}

TEST_CASE("GappBuildSharedPtr", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    std::shared_ptr<Gapp> G = GB.BuildShared();
    
    REQUIRE(G != nullptr);
}

TEST_CASE("GappBuildDefault", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    Gapp* G = GB.Build();
    
    GAppSetting Setting = G->GetSetting();

    REQUIRE(G != nullptr);
    REQUIRE(Setting.APP_NAME == "Graphic application");
    REQUIRE(Setting.SCREEN_WIDTH == 640);
    REQUIRE(Setting.SCREEN_HEIGHT== 480);
    REQUIRE(Setting.ENABLE_CURSOR == false);
    REQUIRE(Setting.ENABLE_DEPTH_TEST == true);
}

TEST_CASE("GappBuildWithSetting", "[graphics][gapp]") 
{
    const std::string Name = "TestGapp";
    const int Width = 100;
    const int Height = 200;
    const bool EnableCursor = true;
    const bool EnableDepth = false;

    GappBuilder& GB = GappBuilder::GetInstance();
    Gapp* G = GB.WithSetting({Name, Width, Height, EnableCursor, EnableDepth})
                .Build();
    
    GAppSetting Setting = G->GetSetting();

    REQUIRE(G != nullptr);
    REQUIRE(Setting.APP_NAME == Name); 
    REQUIRE(Setting.SCREEN_WIDTH == Width);
    REQUIRE(Setting.SCREEN_HEIGHT== Height);
    REQUIRE(Setting.ENABLE_CURSOR == EnableCursor);
    REQUIRE(Setting.ENABLE_DEPTH_TEST == EnableDepth);
}

TEST_CASE("GappBuildWithDefaultScene", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    Gapp* G = GB.WithDefaultScene(1)
                .Build();
    
    GID_t Id = G->GetDefaultScene();

    REQUIRE(G != nullptr);
    REQUIRE(Id == 1); 
}

TEST_CASE("GappBuildWithScenes", "[graphics][gapp]") 
{
    GappBuilder& GB = GappBuilder::GetInstance();
    Gapp* G = GB.WithScenes({1,2,3})
                .Build();
    
    tsl::robin_set Scenes = G->GetScenes();

    REQUIRE(G != nullptr);
    REQUIRE(Scenes.size() == 3);
    REQUIRE(Scenes.contains(1));
    REQUIRE(Scenes.contains(2));
    REQUIRE(Scenes.contains(3)); 
}