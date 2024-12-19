#include <gtest/gtest.h>  

#include <string>
#include <ppm/ppm_f.hpp>

TEST(PPM_Import_test, PPM)
{
    const char* str_expected = "P3 2 2 255 0 0 255 0 255 0 255 0 0 0 0";
    
    char* str;
    ASSERT_TRUE(ppm_import("./result/tests/import_test.ppm", str));

    ASSERT_STREQ(str, str_expected);
    delete[] str;
}

TEST(PPM_Export_test, PPM)
{
    const char* FilePath = "./result/tests/export_test.ppm";

    const char* strtoexported = "P3 2 2 255 0 0 255 0 255 0 255 0 0 0 0";
    
    ASSERT_TRUE(ppm_export(FilePath, strtoexported));

    char* strimported;
    ASSERT_TRUE(ppm_import(FilePath, strimported));

    ASSERT_STREQ(strtoexported, strimported);

    delete[] strimported;
}

