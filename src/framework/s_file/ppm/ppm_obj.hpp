#ifndef PPM_OBJ_HPP
#define PPM_OBJ_HPP

class ppm_obj 
{
private : 
    const char* _magic_byte = "P3";
    unsigned short _width = 0;
    unsigned short _height = 0;
    const int _maxval_color = 255;
    int* _imagepixel=nullptr;

public :
    ppm_obj(const unsigned short  width,
            const unsigned short  height, 
                  int*          imagepixel);
    ~ppm_obj();

    int* GetImage();
    void SetImage(const unsigned short width,
                  const unsigned short height,
                        int*         imagepixel);
    void Save(const char* filepath);
    void Load(const char* filepath);
};

#endif