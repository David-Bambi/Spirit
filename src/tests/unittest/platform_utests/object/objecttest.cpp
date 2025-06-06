#include <catch2/catch_test_macros.hpp>
#include <object/Object.hpp>

TEST_CASE("DefaultConstructor", "[platform][object]") 
{
    Object::NextSeqNo = 0;

    Object* obj1 = new Object();
    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    Object* obj2 = new Object();
    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);

    delete obj2;
}

TEST_CASE("CopyConstructor", "[platform][object]") 
{
    Object::NextSeqNo = 0;

    Object* obj1 = new Object();
    Object* obj2 = new Object(*obj1);

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);

    delete obj1;
    delete obj2;
}

TEST_CASE("Move constructor", "[platform][object]") 
{
    Object::NextSeqNo = 0;

    Object* obj1 = new Object();
    Object* obj2 = new Object(std::move(*obj1));

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == -1);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 0);

    delete obj1;
    delete obj2;
}

TEST_CASE("Assign", "[platform][object]") 
{
    Object::NextSeqNo = 0;

    Object* obj1 = new Object();
    Object* obj2 = obj1;

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 0);

    REQUIRE(obj2 == obj1);

    delete obj1;
}

TEST_CASE("MoveAssign", "[platform][object]") 
{
    Object::NextSeqNo = 0;

    Object* obj1 = new Object();
    Object obj2; 
    obj2 = std::move(*obj1);

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == -1);

    REQUIRE(obj2.SeqNo() == 0);

    REQUIRE(&obj2 != obj1);

    delete obj1;
}
