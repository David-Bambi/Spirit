#include <gtest/gtest.h>  

#include <ppm/ppm_obj.hpp>

TEST(PPM_obj_Constructor,  PPM)
{
int* image = new int[12];
ppm_obj* Test_ppm = new ppm_obj(2,2, image);
ASSERT_FALSE(Test_ppm == nullptr);
delete Test_ppm;
}

TEST(PPM_obj_Load, PPM)
{
ASSERT_TRUE(false);
}

TEST(PPM_obj_Save, PPM)
{
int image [] = {0,255,0,255,255,0,0,0,255,0,0,0};
ppm_obj Test_ppm(2,2, image);

Test_ppm.Save();
ASSERT_TRUE(false);
}
