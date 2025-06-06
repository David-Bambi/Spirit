#include <builder/Builder.hpp>
#include <catch2/catch_test_macros.hpp>
#include <memory>
#include <object/Object.hpp>

class Bidon : public Object
{};

class BidonBuilder : public Builder<Bidon>
{
    public :

    static BidonBuilder& GetInstance()
    {
    static BidonBuilder instance;
    return instance;
    };
};

TEST_CASE("Get a builder instance", "[platform][builder]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    REQUIRE(&BidonBuilder != nullptr);
}

TEST_CASE("Build raw ptr", "[platform][builder]") 
{
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    Bidon* B1 = BidonBuilder.Build();
    Bidon* B2 = BidonBuilder.Build();

    REQUIRE(B1 != nullptr);
    REQUIRE(B2 != nullptr);
    REQUIRE(B1 != B2);

    delete B1;
    delete B2;
}

TEST_CASE("Build unique ptr", "[platform][builder]") 
{
    
    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    std::unique_ptr<Bidon> B1 = BidonBuilder.BuildUnique();
    std::unique_ptr<Bidon> B2 = BidonBuilder.BuildUnique();

    REQUIRE(B1 != nullptr);
    REQUIRE(B2 != nullptr);
    REQUIRE(B1 != B2);   
}


TEST_CASE("Build shared ptr", "[platform][builder]") 
{
    Object::NextSeqNo = 0;
    Builder<Bidon>::DeleteInstance();

    Builder<Bidon>& BidonBuilder = Builder<Bidon>::GetInstance();
    std::shared_ptr<Bidon> BS1 = BidonBuilder.BuildShared();
    std::shared_ptr<Bidon> BS2 = BidonBuilder.BuildShared();

    REQUIRE(BS1 != nullptr);
    REQUIRE(BS2 != nullptr);
    REQUIRE(BS1->SeqNo() == 0);
    REQUIRE(BS2->SeqNo() == 1);
    REQUIRE(BS1 != BS2);
    REQUIRE(BS1.use_count() == 1);
    REQUIRE(BS2.use_count() == 1);
}