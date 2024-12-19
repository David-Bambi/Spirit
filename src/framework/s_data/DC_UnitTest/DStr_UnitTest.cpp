#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <iostream>

#include<../Data/DStr.hpp>
#include <../Data/UnserializeException.hpp>

namespace DStr_UnitTest
    {
        const std::string Directory = "Test_DStr";
    
        void CreateDirectory()
        {
            if (!std::filesystem::exists(Directory))
                std::filesystem::create_directory(Directory);
        }
    }

TEST(StringTest, ToString) 
{
    DStr Str = DStr("Allo");
    std::stringstream StrStream;
    StrStream << Str;
    EXPECT_EQ(StrStream.str(), "Allo");     
}

TEST(StringTest, ToFile)
{
    DStr WriteStr = DStr("Allo");
    DStr_UnitTest::CreateDirectory();
    std::ofstream data_out;
    data_out.open((DStr_UnitTest::Directory + "/" + "StrTest.txt").c_str());
    data_out << WriteStr;
    data_out.close();

    DStr ReadStr = DStr();
    std::ifstream data_in;
    data_in.open((DStr_UnitTest::Directory + "/" + "StrTest.txt").c_str());
    data_in >> ReadStr;
    data_in.close();

    EXPECT_EQ(WriteStr.String(), ReadStr.String()); 
}

TEST(StringTest, UnserializeException)
{
    DStr_UnitTest::CreateDirectory();
    std::ofstream data_out;
    data_out.open((DStr_UnitTest::Directory + "/" + "StrTest.txt").c_str());
    data_out << "Test";
    data_out.close();

    DStr ReadStr = DStr();
    std::ifstream data_in;
    data_in.open((DStr_UnitTest::Directory + "/" + "StrTest.txt").c_str());
    EXPECT_THROW(ReadStr.Unserialize(data_in), UnserializeException);
    data_in.close();
}
