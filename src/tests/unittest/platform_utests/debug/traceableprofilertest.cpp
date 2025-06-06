#include <catch2/catch_test_macros.hpp>
#include <debug/Profiler.hpp>
#include <debug/Traceable.hpp>
#include <debug/Loggers.hpp>
#include <filesystem>
#include <string>
#include <sys/stat.h>

class Bidon : public Traceable 
{
    public : 
        Bidon() : Traceable({"Tag1", "Tag2"}) 
        {
        }        
        std::string TraceStr() const
        {
            return "Test";
        };
};

TEST_CASE("ConstructorProfilTag", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/traceableprofiler1.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Bidon* t1 = new Bidon();
    REQUIRE(t1 != nullptr);
    REQUIRE(Profiler::Table.find(t1) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    Profiler::Trace("Tag1", t1);
    Profiler::Trace("Tag2", t1);
    Profiler::Trace("Tag3", t1);

    spdlog::get("profiler")->flush();

    delete t1;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 38);
}

TEST_CASE("CopyConstructorProfilMissingTag", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/traceableprofiler2.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Bidon* B1 = new Bidon();
    Bidon* B2 = new Bidon(*B1);

    REQUIRE(B2 != nullptr);
    REQUIRE(Profiler::Table.find(B2) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 2);

    Profiler::Trace("Tag1", B2);
    Profiler::Trace("Tag2", B2);
    Profiler::Trace("Tag3", B2);

    spdlog::get("profiler")->flush();

    delete B1;
    delete B2;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 38);
}