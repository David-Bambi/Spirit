#include <Algo.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "stb_image_write.h"
#include <spdlog/spdlog.h>

int main ()
{
int width = 300;
int height = 300;
int channels = 3;

unsigned char* image = (unsigned char*)malloc(width * height * channels);

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        double val = ALGO::RandomNoise(256.0);
            
        unsigned char red = (unsigned char)(val) ;
        unsigned char green = (unsigned char)(val);
        unsigned char blue = (unsigned char)(val);

        int offset = (i + j * width) * channels;
        image[offset + 0] = red;
        image[offset + 1] = green;
        image[offset + 2] = blue;
    }    
}

stbi_write_png("test.png", width, height, channels, image, width * channels);
free(image);
return 0;
}