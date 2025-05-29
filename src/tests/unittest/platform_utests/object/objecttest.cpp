// tests/test_my_code.cpp
#include <catch2/catch_test_macros.hpp>

#include <memory>
#include <iostream>
#include <typeindex>
#include <unordered_map>
#include <object/Object.hpp>

class Bidon : public Object
{
    public :
        Bidon() {  }
        Bidon(const Bidon& obj) : Object(obj) { }
        Bidon(Bidon&& obj) noexcept : Object(std::move(obj)) {  }
        Bidon& operator=(const Bidon& obj) { Object::operator=(obj); return *this; }
        Bidon& operator=(Bidon&& obj) noexcept { Object::operator=(std::move(obj)); return *this; }
        virtual ~Bidon() {};
};

TEST_CASE("Default constructor.", "[DefaultConstructor]") 
{
    Object::NextSeqNo = 0;

    Object* obj = new Object();
    REQUIRE(obj != nullptr);
    REQUIRE(obj->SeqNo() == 0);

    delete obj;
}

TEST_CASE("Multiple Default constructor.", "[MultipleDefaultConstructor]") 
{
    Object::NextSeqNo = 0;
    
    Object* obj1 = new Object();
    Object* obj2 = new Object();

    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);

    delete obj1;
    delete obj2;
}

TEST_CASE("Copy constructor.", "[CopyConstructor]") 
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

TEST_CASE("Move constructor.", "[MoveConstructor]") 
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

TEST_CASE("Assign object.", "[AssignObject]") 
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

TEST_CASE("Move Assign object.", "[MoveAssignObject]") 
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

TEST_CASE("Test with child class.", "[ChildClassObject]") 
{
    Object::NextSeqNo = 0;

    Bidon* obj1 = new Bidon();
    REQUIRE(obj1 != nullptr);
    REQUIRE(obj1->SeqNo() == 0);

    Bidon* obj2 = new Bidon(*obj1);
    REQUIRE(obj2 != nullptr);
    REQUIRE(obj2->SeqNo() == 1);
    REQUIRE(obj2 != obj1);
    
    Bidon* obj3 = new Bidon(std::move(*obj1));
    REQUIRE(obj3 != nullptr);
    REQUIRE(obj3->SeqNo() == 0);
    REQUIRE(obj1->SeqNo() == -1);
    REQUIRE(obj3 != obj1);
    
    Bidon* obj4 = obj2;
    REQUIRE(obj4 != nullptr);
    REQUIRE(obj4->SeqNo() == 1);
    REQUIRE(obj4 == obj2);
    
    Bidon obj5;
    obj5 = std::move(*obj3);
    REQUIRE(obj3 != nullptr);
    REQUIRE(obj5.SeqNo() == 0);
    REQUIRE(&obj5 != obj3);

    delete obj1;
    delete obj2;
    delete obj3;
}


