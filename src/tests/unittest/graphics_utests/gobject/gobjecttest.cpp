#include <catch2/catch_test_macros.hpp>
#include <debug/Profiler.hpp>
#include <filesystem>
#include <gobject/GraphicObject.hpp>
#include <debug/Loggers.hpp>
#include <gobject/UGID.hpp>
#include <string>
#include <sys/stat.h>

class Bidon : public GraphicObject
{
    public :
        Bidon() : GraphicObject()
        {};

        std::string TraceStr() const
        {
            return "Bidon : " + std::to_string(SeqNo());
        };
};

class Bidon2 : public Bidon
{
    public :
        Bidon2()
        {
            Profiler::Unregister(this, {"INIT", "RENDER"});
        };
};

TEST_CASE("DefaultConstructor.", "[graphics][object]") 
{
    Object::NextSeqNo = 0;
    UGID::Clear();

    GraphicObject* obj1 = new GraphicObject();
    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);
    REQUIRE(obj1->GID() == -1);

    delete obj1;
}

TEST_CASE("CopyConstructor.", "[graphics][object]") 
{
    Object::NextSeqNo = 0;
    UGID::Clear();

    GraphicObject* obj1 = new GraphicObject();
    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);
    REQUIRE(obj1->GID() == -1);

    GraphicObject* obj2 = new GraphicObject(*obj1);
    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);
    REQUIRE(obj1->GID() == -1);

    delete obj1;
    delete obj2;
}

TEST_CASE("Child class constructor.", "[graphics][object]") 
{
    Object::NextSeqNo = 0;
    const char* PathFile = "logs/graphicsobjectchild.trc";
    Loggers::Init("profiler", PathFile);

    Bidon* obj1 = new Bidon();
    Bidon2* obj2 = new Bidon2();

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);

    Profiler::Trace("INIT", obj1);
    Profiler::Trace("RENDER", obj1);
    Profiler::Trace("CLEAN", obj1);

    Profiler::Trace("INIT", obj2);
    Profiler::Trace("RENDER", obj2);
    Profiler::Trace("CLEAN", obj2);
        
    spdlog::get("profiler")->flush();

    REQUIRE(std::filesystem::exists(PathFile));
    REQUIRE(std::filesystem::file_size(PathFile) == 248);

    delete obj1;
    delete obj2;
}

TEST_CASE("Destructor.", "[graphics][object]") 
{
    Object::NextSeqNo = 0;

    Bidon* obj1 = new Bidon();
    Bidon* obj2 = new Bidon();

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);
    REQUIRE(Profiler::Table.size() == 2);

    delete obj1;
    REQUIRE(Profiler::Table.size() == 1);

    delete obj2;
    REQUIRE(Profiler::Table.size() == 0);
}

TEST_CASE("SetGID.", "[graphics][object]") 
{
    UGID::Clear();

    GraphicObject* obj1 = new GraphicObject();
    obj1->SetGID();

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->GID() == 0);

    delete obj1;

    GraphicObject* obj2 = new GraphicObject();
    obj2->SetGID();
    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->GID() == 0);

    GraphicObject* obj3 = new GraphicObject();
    obj3->SetGID();
    REQUIRE(obj3 != nullptr);
    REQUIRE(obj3->GID() == 1);

    delete obj2;
    delete obj3;
}


TEST_CASE("SetGIDName.", "[graphics][object]") 
{
    UGID::Clear();

    GraphicObject* obj1 = new GraphicObject();
    obj1->SetGID("Test1");

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->GID() == UGID::Get("Test1"));

    delete obj1;

    GraphicObject* obj2 = new GraphicObject();
    obj2->SetGID("Test2");
    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->GID() == UGID::Get("Test2"));

    GraphicObject* obj3 = new GraphicObject();
    obj3->SetGID("Test3");
    REQUIRE(obj3 != nullptr);
    REQUIRE(obj3->GID() == UGID::Get("Test3"));

    delete obj2;
    delete obj3;
}

