#include <catch2/catch_test_macros.hpp>

#include <object/Object.hpp>
#include <debug/Profiler.hpp>
#include <iostream>

TEST_CASE("Register and unregister object", "[RegisterUnregisterObject]") 
{
    Object* obj = new Object();
    REQUIRE(obj != nullptr);
    REQUIRE(Profiler::Table.find(obj) != Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 1);

    delete obj;

    REQUIRE(Profiler::Table.find(obj) == Profiler::Table.end());
    REQUIRE(Profiler::Table.size() == 0);
}