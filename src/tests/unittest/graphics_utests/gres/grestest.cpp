#include <catch2/catch_test_macros.hpp>
#include <gobject/UGID.hpp>
#include <gres/RessourceManager.hpp>

TEST_CASE("RessourceManagerSingleton", "[graphics][gres]") 
{
    RessourceManager& RM = RessourceManager::Instance();
    REQUIRE(&RM == &RessourceManager::Instance());
}

TEST_CASE("RessourceManagerSingleton", "[graphics][gres]") 
{
    RessourceManager& RM = RessourceManager::Instance();
    REQUIRE(&RM == &RessourceManager::Instance());
}