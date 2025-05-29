// tests/test_my_code.cpp
#include <catch2/catch_test_macros.hpp>

#include <singleton/Singleton.hpp>

class Bidon : public Singleton<Bidon>
{};

TEST_CASE("Singleton 1", "[platform][singleton]") 
{
    Bidon& B1 = Bidon::Instance();
    Bidon& B2 = Bidon::Instance();

    REQUIRE(&B1 == &B2);
}


