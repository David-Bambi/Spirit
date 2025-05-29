#include <catch2/catch_test_macros.hpp>
#include <debug/Profiler.hpp>
#include <debug/Traceable.hpp>
#include <string>
#include <type_traits>

class Bidon : public Traceable 
{
    public :
        std::string TraceStr() const
        {
            return "Test";
        };
};


TEST_CASE("Traceable is abstract", "[Debug][Platform]") 
{
    STATIC_REQUIRE(std::is_abstract<Traceable>::value); 
}

TEST_CASE("Constructor", "[Debug][Platform]") 
{
    Profiler::Table.clear();

    Traceable* B = new Bidon();
    REQUIRE(Profiler::Table.size() == 1);
    std::string Res = B->TraceStr();
    REQUIRE(Res=="Test");
    delete B;
    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("Constructor copy", "[Debug][Platform]") 
{
    Profiler::Table.clear();

    Bidon* B = new Bidon();
    Traceable* B2 = new Bidon(*B);

    REQUIRE(Profiler::Table.size() == 2);
    std::string Res = B->TraceStr();
    REQUIRE(Res=="Test");
    delete B;
    REQUIRE(Profiler::Table.size() == 1);

    Res = B2->TraceStr();
    REQUIRE(Res=="Test");
    delete B2;
    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("Type", "[Debug][Platform]") 
{
    Profiler::Table.clear();

    Bidon* B = new Bidon();
    Traceable* B2 = new Bidon(*B);

    REQUIRE(Profiler::Table.size() == 2);
    std::string Res = B->TraceStr();
    REQUIRE(Res=="Test");
    delete B;
    REQUIRE(Profiler::Table.size() == 1);

    Res = B2->TraceStr();
    REQUIRE(Res=="Test");
    delete B2;
    REQUIRE(Profiler::Table.size() == 0);
}
