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

int colorvalmax = 0.0;
int colovalmin = 255.0;

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        double xnorm = ((j /(double) width));
        double ynorm = ((i /(double) height));

        double noise = ALGO::PerlinNoiseWithOctave(xnorm, ynorm, 4 /*frequency*/, 2.0 /*amplitude*/, 5 /*octave*/);

        double coloval = ALGO::Normalize(noise, -1.0, 1.0) * 255.0f;
        if (coloval > colorvalmax) colorvalmax = coloval;
        if (coloval < colovalmin) colovalmin = coloval;

        int offset = (i + j * width) * channels;
        image[offset + 0] = coloval;
        image[offset + 1] = coloval;
        image[offset + 2] = coloval;
    }    
}

for (int i = 0; i < width * height * channels ; i++)
{   
    image[i] = (unsigned char) (ALGO::Normalize(image[i], colorvalmax, colovalmin) * 255);
}

stbi_write_png("test.png", width, height, channels, image, width * channels);
free(image);
return 0;
}