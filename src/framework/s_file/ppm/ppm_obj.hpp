#ifndef PPM_OBJ_HPP
#define PPM_OBJ_HPP

class ppm_obj 
{
private : 
    const char* _magic_byte = "P6";
    unsigned short _width = 0;
    unsigned short _height = 0;
    const int _maxval_color = 255;
    float* _imagepixel=nullptr;

public :
    ppm_obj(const unsigned short  width,
            const unsigned short  height, 
                  float*          imagepixel);
    ~ppm_obj();

    float* GetImage();
    void SetImage(const unsigned short width,
                  const unsigned short height,
                        float*         imagepixel);
    void Save(const char* filepath);
    void Load(const char* filepath);
};

#endif