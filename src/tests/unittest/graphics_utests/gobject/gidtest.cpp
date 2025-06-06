#include <catch2/catch_test_macros.hpp>
#include <gobject/UGID.hpp>

TEST_CASE("Clear", "[graphics][gid]") 
{
    UGID::Clear();

    GID_t id1 = UGID::Get();
    REQUIRE(id1 == 0);

    GID_t id2 = UGID::Get("test1");
    REQUIRE(id2 == 1);
    REQUIRE(UGID::Get("test1") == id2);

    GID_t id3 = UGID::Get();
    REQUIRE(id3 == 2);

    UGID::Free(id1);
    GID_t id4 = UGID::Get();
    REQUIRE(id4 == 0);

    UGID::Clear();

    GID_t id5 = UGID::Get();
    REQUIRE(id5 == 0);

    GID_t id6 = UGID::Get("test1");
    REQUIRE(id6 == 1);
    REQUIRE(UGID::Get("test1") == id6);

    GID_t id7 = UGID::Get();
    REQUIRE(id7 == 2);

    UGID::Free(id1);
    GID_t id8 = UGID::Get();
    REQUIRE(id8 == 0);
}


TEST_CASE("Get", "[graphics][gid]") 
{
    UGID::Clear();

    GID_t id1 = UGID::Get();
    REQUIRE(id1 == 0);

    GID_t id2 = UGID::Get();
    REQUIRE(id2 == 1);
}

TEST_CASE("GetName", "[graphics][gid]") 
{
    UGID::Clear();

    GID_t id1 = UGID::Get("test1");
    REQUIRE(id1 == 0);
    REQUIRE(UGID::Get("test1") == id1);
    REQUIRE(UGID::Get("test2") == 1);
}

TEST_CASE("SetMixedGID", "[graphics][gid]") 
{
    UGID::Clear();

    GID_t id1 = UGID::Get("test1");
    REQUIRE(id1 == 0);
    REQUIRE(UGID::Get("test1") == id1);
    
    GID_t id2 = UGID::Get();
    REQUIRE(id2 == 1);

    GID_t id3 = UGID::Get("test2");
    REQUIRE(id3 == 2);
    REQUIRE(UGID::Get("test2") == id3);

    GID_t id4 = UGID::Get();
    REQUIRE(id4 == 3);

    REQUIRE(UGID::Get("test1") == id1);
    REQUIRE(UGID::Get("test2") == id3);
}

TEST_CASE("Recycle", "[graphics][gid]") 
{
    UGID::Clear();

    GID_t id1 = UGID::Get("test1");
    REQUIRE(id1 == 0);
    GID_t id2 = UGID::Get();
    REQUIRE(id2 == 1);
    GID_t id3 = UGID::Get();
    REQUIRE(id3 == 2);
    GID_t id4 = UGID::Get("test4");
    REQUIRE(id4 == 3);

    UGID::Free(id1);
    GID_t id5 = UGID::Get();
    REQUIRE(id5 == 0);
    GID_t id6 = UGID::Get();
    REQUIRE(id6 == 4);

    REQUIRE(UGID::Get("test1") == 0);

    UGID::Free(id5);
    UGID::Free(id2);
    UGID::Free("test4");

    REQUIRE(UGID::Get("test4") == 0);
    REQUIRE(UGID::Get() == 1);
    REQUIRE(UGID::Get("test5") == 3);
    REQUIRE(UGID::Get() == 5);
}