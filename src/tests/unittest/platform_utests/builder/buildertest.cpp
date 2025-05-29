#include <catch2/catch_test_macros.hpp>

#include <builder/Builder.hpp>
#include <memory>
#include <object/Object.hpp>

class Bidon : public Object
{};

TEST_CASE("Get a builder instance", "[GetInstance]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    REQUIRE(&BidonBuilder != nullptr);
}

TEST_CASE("Build raw ptr", "[Build_RawPtr]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    Bidon* B1 = BidonBuilder.Build();
    Bidon* B2 = BidonBuilder.Build();

    REQUIRE(B1 != nullptr);
    REQUIRE(B2 != nullptr);
    REQUIRE(B1 != B2);

    delete B1;
    delete B2;
}

TEST_CASE("Build unique ptr", "[Build_UniquePtr]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    std::unique_ptr<Bidon> B1 = BidonBuilder.BuildUnique();
    std::unique_ptr<Bidon> B2 = BidonBuilder.BuildUnique();

    REQUIRE(B1 != nullptr);
    REQUIRE(B2 != nullptr);
    REQUIRE(B1 != B2);
}


TEST_CASE("Build shared ptr", "[Build_SharedPtr]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    std::shared_ptr<Bidon> B1 = BidonBuilder.BuildShared();
    std::shared_ptr<Bidon> B2 = BidonBuilder.BuildShared();

    REQUIRE(B1 != nullptr);
    REQUIRE(B2 != nullptr);
    REQUIRE(B1 != B2);
    REQUIRE(B1.use_count() == 1);
    REQUIRE(B2.use_count() == 1);
}