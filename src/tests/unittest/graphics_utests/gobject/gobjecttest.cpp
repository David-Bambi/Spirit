#include <catch2/catch_test_macros.hpp>
//#include <debug/Profiler.hpp>
#include <filesystem>
//#include <object/Object.hpp>
#include <string>
#include <sys/stat.h>

class Bidon 
{
    // public :
    //     std::string TraceStr() const
    //     {
    //         return "TEST";
    //     };
};

class Bidon2 
{
    // public :
    //     Bidon2()
    //     {
    //         Profiler::Unregister(this, {"INIT", "RENDER"});
    //     };

    //     std::string TraceStr() const
    //     {
    //         return "TEST2";
    //     };
};

TEST_CASE("Default constructor.", "[graphics][object]") 
{
    // Object::NextSeqNo = 0;
    // const char* PathFile = "logs/graphicsobject.trc";
    // Loggers::Init("profiler", PathFile);

    // Bidon* obj1 = new Bidon();

    // REQUIRE(obj1 != nullptr);
    // REQUIRE(obj1->SeqNo() == 0);

    // Profiler::Trace("INIT", obj1);
    // Profiler::Trace("RENDER", obj1);
    // Profiler::Trace("CLEAN", obj1);
        
    // spdlog::get("profiler")->flush();

    // REQUIRE(std::filesystem::exists(PathFile));
    // REQUIRE(std::filesystem::file_size(PathFile) == 171);

    // delete obj1;
}


// TEST_CASE("Copy constructor.", "[graphics][object]") 
// {
//     Object::NextSeqNo = 0;
//     const char* PathFile = "logs/graphicsobjectcopy.trc";
//     Loggers::Init("profiler", PathFile);

//     Bidon* obj1 = new Bidon();
//     Bidon* obj2 = new Bidon(*obj1);

//     REQUIRE(obj1 != nullptr);
//     REQUIRE(obj1->SeqNo() == 0);

//     REQUIRE(obj2 != nullptr);
//     REQUIRE(obj2->SeqNo() == 1);

//     Profiler::Trace("INIT", obj1);
//     Profiler::Trace("RENDER", obj1);
//     Profiler::Trace("CLEAN", obj1);

//     Profiler::Trace("INIT", obj2);
//     Profiler::Trace("RENDER", obj2);
//     Profiler::Trace("CLEAN", obj2);
        
//     spdlog::get("profiler")->flush();

//     REQUIRE(std::filesystem::exists(PathFile));
//     REQUIRE(std::filesystem::file_size(PathFile) == 342);

//     delete obj1;
//     delete obj2;
// }

// TEST_CASE("Child class constructor.", "[graphics][object]") 
// {
//     Object::NextSeqNo = 0;
//     const char* PathFile = "logs/graphicsobjectchild.trc";
//     Loggers::Init("profiler", PathFile);

//     Bidon* obj1 = new Bidon();
//     Bidon2* obj2 = new Bidon2();

//     REQUIRE(obj1 != nullptr);
//     REQUIRE(obj1->SeqNo() == 0);

//     REQUIRE(obj2 != nullptr);
//     REQUIRE(obj2->SeqNo() == 1);

//     Profiler::Trace("INIT", obj1);
//     Profiler::Trace("RENDER", obj1);
//     Profiler::Trace("CLEAN", obj1);

//     Profiler::Trace("INIT", obj2);
//     Profiler::Trace("RENDER", obj2);
//     Profiler::Trace("CLEAN", obj2);
        
//     spdlog::get("profiler")->flush();

//     REQUIRE(std::filesystem::exists(PathFile));
//     REQUIRE(std::filesystem::file_size(PathFile) == 229);

//     delete obj1;
//     delete obj2;
// }
