#ifndef PPM_OBJ_HPP
#define PPM_OBJ_HPP

class ppm_obj 
{
private : 
    const char* _file = "result.ppm";
    const char* _magic_byte = "P3";
    int _width = 0;
    int _height = 0;
    const int _maxval_color = 255;
    const int* _imagepixel;

public :
    ppm_obj(int width, int height, const int* imagepixel);
    ~ppm_obj();

    void SetImage(int width, int height, const int* imagepixel);
    void Save();
    void Load();

};

#endif