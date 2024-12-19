#include<ppm/ppm_obj.hpp>

#include <string>
#include <ppm/ppm_f.hpp>
#include <cstring>
#include <iostream>

ppm_obj::ppm_obj( const unsigned short width,
                  const unsigned short height, 
                        float*         imagepixel)
{
_width = width;
_height = height;

int size = (width * height) *3;
_imagepixel = new float[size*sizeof(float)];
std::memcpy(_imagepixel, imagepixel, size);
}

ppm_obj::~ppm_obj()
{
delete [] _imagepixel;
_imagepixel = nullptr;
}

void ppm_obj::SetImage( const unsigned short width,  
                        const unsigned short height, 
                              float*         imagepixel)
{
_width = width;
_height = height;
_imagepixel = imagepixel;
}

float* ppm_obj::GetImage()
{
return _imagepixel;
}

void ppm_obj::Save(const char* filepath)
{
std::string strtosave;
strtosave += _magic_byte;
strtosave += " ";
strtosave += std::to_string(_width);
strtosave += " ";
strtosave += std::to_string(_height);
strtosave += " ";
strtosave += std::to_string(_maxval_color);
strtosave += " ";

int size = (_width * _height) *3;
for(unsigned short i=0; i<size; i++)
    {
    strtosave += " ";
    std::cout <<  std::to_string(_imagepixel[i]); std::cout<<std::endl;
    strtosave += std::to_string(_imagepixel[i]);
    }

ppm_export(filepath, strtosave.c_str());
}


void ppm_obj::Load(const char* filepath)
{

}
