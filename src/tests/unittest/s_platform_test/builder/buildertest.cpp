// tests/test_my_code.cpp
#include <catch2/catch_test_macros.hpp>

#include <memory>
#include <builder/Builder.hpp>

class Bidon
{
    public:
        Bidon()=default;
};

TEST_CASE("Get a builder instance", "[GetInstance]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    REQUIRE(&BidonBuilder != nullptr);
}

TEST_CASE("Get a builder instance", "[Build]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    std::unique_ptr<Bidon> Bidon =  BidonBuilder.Build();

    REQUIRE(Bidon != nullptr);
}