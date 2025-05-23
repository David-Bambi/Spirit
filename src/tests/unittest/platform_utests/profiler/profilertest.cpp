#include <catch2/catch_test_macros.hpp>

#include <object/Object.hpp>
#include <builder/Builder.hpp>
#include <debug/Profiler.hpp>
#include <iostream>

#include <filesystem>
#include <sys/stat.h>

class Bidon : public Object { int i = 1; };

TEST_CASE("Register and unregister object", "[RegisterUnregisterObject]") 
{
    Object::NextSeqNo = 0;
    Profiler::Table.clear();

    Object* obj = new Object();
    REQUIRE(obj != nullptr);
    REQUIRE(Profiler::Table.find(obj) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    delete obj;

    REQUIRE(Profiler::Table.find(obj) == Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("Table Dump", "[TableDump]") 
{
    Object::NextSeqNo = 0;
    Profiler::Table.clear();

    const char* PathFile = "logs/tabledump.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Object* obj = new Object();
    REQUIRE(obj != nullptr);
    REQUIRE(Profiler::Table.find(obj) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    Object* obj2 = new Object();
    REQUIRE(obj2 != nullptr);
    REQUIRE(Profiler::Table.find(obj2) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 2);

    Profiler::TableDump();
    spdlog::get("profiler")->flush();

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 110);
}

TEST_CASE("Summary Table Dump", "[SummaryTableDump]") 
{
    Object::NextSeqNo = 0;
    Profiler::Table.clear();

    const char* PathFile = "logs/summarytabledump.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Object* obj = new Object();
    REQUIRE(obj != nullptr);
    REQUIRE(Profiler::Table.find(obj) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    Object* obj2 = new Bidon();
    REQUIRE(obj2 != nullptr);
    REQUIRE(Profiler::Table.find(obj2) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 2);

    Profiler::SummaryTableDump();
    spdlog::get("profiler")->flush();

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 87);
}


TEST_CASE("Objec profile", "[ObjectProfile]") 
{
    Object::NextSeqNo = 0;
    Profiler::Table.clear();

    const char* PathFile = "logs/objectprofile.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Object* obj = new Object();
    obj->ActivateTrace({"INIT", "TEST"});
    REQUIRE(obj != nullptr);

    Profiler::Trace("INIT", *obj);
    Profiler::Trace("TEST", *obj);
    Profiler::Trace("RENDER", *obj);

    spdlog::get("profiler")->flush();

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 124);
}

TEST_CASE("Objec builder profile", "[ObjectBuilderProfile]") 
{
    Object::NextSeqNo = 0;
    Profiler::Table.clear();

    const char* PathFile = "logs/objectbuilderprofile.log";
    Loggers::Init("profiler", PathFile);
    spdlog::get("profiler")->set_pattern("[%l] %v");

    Object* obj1 = Builder<Object>::GetInstance().WithTrace({"INIT"}).Build();
    Object* obj2 = Builder<Object>::GetInstance().WithTrace({"CLEAN"}).Build();

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj2 != nullptr);

    Profiler::Trace("INIT", *obj1);
    Profiler::Trace("CLEAN", *obj1);
    Profiler::Trace("INIT", *obj2);
    Profiler::Trace("CLEAN", *obj2);

    spdlog::get("profiler")->flush();

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 125);
}