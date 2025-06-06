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
            return "Bidon";
        };
};

class Bidon2 : public Traceable 
{
    public :
        Bidon2 () : Traceable({"Tag1", "Tag2"})
        {
        }
        std::string TraceStr() const
        {
            return "Bidon2";
        };
};


TEST_CASE("TraceableIsAbstract", "[Debug][Platform]") 
{
    STATIC_REQUIRE(std::is_abstract<Traceable>::value); 
}

TEST_CASE("Constructor", "[Debug][Platform]") 
{
    Profiler::Table.clear();

    Traceable* B = new Bidon();
    REQUIRE(Profiler::Table.size() == 1);

    Traceable* B2 = new Bidon2();
    REQUIRE(Profiler::Table.size() == 2);

    std::string Res = B->TraceStr();
    REQUIRE(Res=="Bidon");

    Res = B2->TraceStr();
    REQUIRE(Res=="Bidon2");

    delete B;
    delete B2;

    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("ConstructorCopy", "[Debug][Platform]") 
{
    Profiler::Table.clear();

    Bidon* A = new Bidon();
    Traceable* B = new Bidon(*A);

    Bidon2* AA = new Bidon2();
    Traceable* BB = new Bidon2(*AA);

    REQUIRE(Profiler::Table.size() == 4);

    std::string Res1 = A->TraceStr();
    REQUIRE(Res1=="Bidon");
    std::string Res2 = B->TraceStr();
    REQUIRE(Res2=="Bidon");

    std::string ResAA = AA->TraceStr();
    REQUIRE(ResAA=="Bidon2");
    std::string c = BB->TraceStr();
    REQUIRE(ResAA=="Bidon2");

    delete A;
    REQUIRE(Profiler::Table.size() == 3);

    delete B;
    REQUIRE(Profiler::Table.size() == 2);

    delete AA;
    REQUIRE(Profiler::Table.size() == 1);

    delete BB;
    REQUIRE(Profiler::Table.size() == 0);
}
