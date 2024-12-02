#ifndef PPM_F
#define PPM_F

#include <string>

bool ppm_export (const char* filepath, const char* strtoexport);
bool ppm_import(const char* filepath, char*& outstr);


#endif