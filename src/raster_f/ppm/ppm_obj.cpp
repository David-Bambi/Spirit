#include<ppm/ppm_obj.hpp>

ppm_obj::ppm_obj(int width, int height, const int* imagepixel)
{
_width = width;
_height = height;
_imagepixel = imagepixel;
}

ppm_obj::~ppm_obj()
{
delete [] _imagepixel;
_imagepixel = nullptr;
}

void ppm_obj::SetImage(int width, int height, const int* imagepixel)
{
_width = width;
_height = height;
delete [] _imagepixel;
_imagepixel = imagepixel;
}


void ppm_obj::Save()
{

}


void ppm_obj::Load()
{

}
