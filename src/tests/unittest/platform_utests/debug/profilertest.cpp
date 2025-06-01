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
        std::string TraceStr() const
        {
            return "Test";
        };
};

TEST_CASE("Register and unregister object", "[platform][profiler]") 
{
    Profiler::Table.clear();

    Traceable* t = new Bidon();
    REQUIRE(t != nullptr);
    REQUIRE(Profiler::Table.find(t) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    delete t;

    REQUIRE(Profiler::Table.find(t) == Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("Table Dump", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/tabledump.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Bidon* t1 = new Bidon();
    REQUIRE(t1 != nullptr);
    REQUIRE(Profiler::Table.find(t1) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    Bidon* t2 = new Bidon();
    REQUIRE(t2 != nullptr);
    REQUIRE(Profiler::Table.find(t2) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 2);

    Profiler::TableDump();
    spdlog::get("profiler")->flush();

    delete t1;
    delete t2;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 90);
}

TEST_CASE("Summary Table Dump", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/summarytabledump.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Bidon* B1 = new Bidon();
    REQUIRE(B1 != nullptr);
    REQUIRE(Profiler::Table.find(B1) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    Traceable* B2 = new Bidon();
    REQUIRE(B2 != nullptr);
    REQUIRE(Profiler::Table.find(B2) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 2);

    Profiler::SummaryTableDump();
    spdlog::get("profiler")->flush();

    delete B1;
    delete B2;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 44);
}


TEST_CASE("Register with new tag", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/traceabletrace.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Traceable* t1 = new Bidon();
    Profiler::Register(t1, {"ALLOC", "INIT", "TEST"});
    REQUIRE(t1 != nullptr);

    Profiler::Trace("ALLOC", t1);
    Profiler::Trace("TEST", t1);
    Profiler::Trace("RENDER", t1);

    spdlog::get("profiler")->flush();

    delete t1;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 39);
}

TEST_CASE("Unregister tag", "[platform][profiler]") 
{
    Profiler::Table.clear();

    const char* PathFile = "logs/traceablewithouttag.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Traceable* t1 = new Bidon();
    Profiler::Register(t1, {"ALLOC", "BUILD", "FREE"});
    Profiler::Unregister(t1, {"ALLOC", "BUILD"});
    REQUIRE(t1 != nullptr);

    Profiler::Trace("ALLOC", t1);
    Profiler::Trace("BUILD", t1);
    Profiler::Trace("FREE", t1);

    spdlog::get("profiler")->flush();

    delete t1;

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 19);
}