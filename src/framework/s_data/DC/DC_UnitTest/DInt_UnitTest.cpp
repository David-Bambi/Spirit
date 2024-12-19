#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iostream>

#include <../Data/DInt.hpp>
#include <../Data/UnserializeException.hpp>

namespace DInt_UnitTest
    {
        const std::string Directory = "Test_Dint";
    
        void CreateDirectory()
        {
            if (!std::filesystem::exists(Directory))
                std::filesystem::create_directory(Directory);
        }
    }

TEST(IntegerTest, ToString) 
{
    DInt Int = DInt(4);
    std::stringstream IntStream;
    IntStream << Int;
    EXPECT_EQ(IntStream.str(), "4");     
}

TEST(IntegerTest, ToFile)
{
    DInt WriteInt = DInt(4);
    DInt_UnitTest::CreateDirectory();
    std::ofstream data_out;
    data_out.open((DInt_UnitTest::Directory + "/" + "IntTest.txt").c_str());
    data_out << WriteInt;
    data_out.close();

    DInt ReadInt = DInt();
    std::ifstream data_in;
    data_in.open((DInt_UnitTest::Directory + "/" + "IntTest.txt").c_str());
    data_in >> ReadInt;
    data_in.close();

    EXPECT_EQ(WriteInt.Integer(), ReadInt.Integer()); 
}

TEST(IntegerTest, UnserializeException)
{
    DInt_UnitTest::CreateDirectory();
    std::ofstream data_out;
    data_out.open((DInt_UnitTest::Directory + "/" + "IntegerTest.txt").c_str());
    data_out << "Test";
    data_out.close();

    DInt ReadInteger = DInt();
    std::ifstream data_in;
    data_in.open((DInt_UnitTest::Directory + "/" + "IntegerTest.txt").c_str());

    EXPECT_THROW(ReadInteger.Unserialize(data_in), UnserializeException);
    data_in.close();
}

TEST(IntegerTest, CompareTo)
{
    DInt Big = DInt(1000);
    DInt Small = DInt(1);
    DInt SameAsSmall = DInt(1);
    DInt LessThanSmall = DInt(-10);

    EXPECT_TRUE(Small < Big);
    EXPECT_TRUE(Big > Small);
    EXPECT_FALSE(SameAsSmall > Small);
    EXPECT_FALSE(SameAsSmall < Small);

    EXPECT_TRUE(SameAsSmall == Small);
    EXPECT_TRUE(Big >= Small);
    EXPECT_TRUE(SameAsSmall >= Small);
    EXPECT_TRUE(SameAsSmall <= Small);
    EXPECT_TRUE(LessThanSmall <= Small);

    EXPECT_TRUE(SameAsSmall != LessThanSmall);
    EXPECT_FALSE(SameAsSmall != Small);
}



