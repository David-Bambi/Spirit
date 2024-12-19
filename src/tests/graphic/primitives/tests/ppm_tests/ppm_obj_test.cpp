#include <gtest/gtest.h>  

#include <ppm/ppm_obj.hpp>

TEST(PPM_obj_Constructor,  PPM)
{
float* image = new float[12];
ppm_obj* Test_ppm = new ppm_obj(2,2, image);
ASSERT_FALSE(Test_ppm == nullptr);
delete Test_ppm;
}

TEST(PPM_obj_SaveLoad, PPM)
{
float image [] = {0,255,0,255,255,0,0,0,255,0,0,0};
ppm_obj Test_ppm(2,2, image);

Test_ppm.Save("./result/tests/saveload.ppm");
Test_ppm.Load("./result/tests/saveload.ppm");

float* image2 = Test_ppm.GetImage(); 

for(unsigned short i; i<sizeof(image); i++)
{
    ASSERT_TRUE(image[i] == image2[i]);
}

ASSERT_TRUE(false);
}
