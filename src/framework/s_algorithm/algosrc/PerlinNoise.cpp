#include <Algo.hpp>

#include <cmath>

/**
 * @brief Perlin Noise implementation
 * @author Ken Perlin
 * The perlin noise algorithm is used for generate value between 0 and 1. The result is a 
 * smooth noise.
 * 
 * This implementation is based on https://adrianb.io/2014/08/09/perlinnoise.html exemple.
 */
namespace PerlinNoise
{
    const int p [512] = { 151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,
        140,36,103,30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,
        203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,
        48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,102,
        143,54, 65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,
        86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,
        207,206,59,227,47,16,58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,221,
        153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,224,232,178,185,112,104,218,246,
        97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,49,192,
        214,31,181,199,106,157,184, 84,204,176,115,121,50,45,127,4,150,254,138,236,205,93,222,114,
        67,29,24,72,243,141,128,195,78,66,215,61,156,180,

        151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,
        140,36,103,30,69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,
        203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,74,165,71,134,139,
        48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,102,
        143,54, 65,25,63,161,1,216,80,73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,
        86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,
        207,206,59,227,47,16,58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,221,
        153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,224,232,178,185,112,104,218,246,
        97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,49,192,
        214,31,181,199,106,157,184, 84,204,176,115,121,50,45,127,4,150,254,138,236,205,93,222,114,
        67,29,24,72,243,141,128,195,78,66,215,61,156,180
    };

    double fade (double t);
    int permutation (int x);
    double grad2D (int hash, double x, double y);
    double lerp (double t, double a, double b);
}

/**
 * @brief Permutation function : This function is used to get value in the permutation table.
 * 
 * @param x : The index in the permutation table. The value is between 0 and 255.
 * @return int : The value in the permutation table at index x.
 */
int PerlinNoise::permutation(int x) {
    return p[x % 256];
}


/**
 * @brief Fade function : Fade function as defined by Ken Perlin.  This eases coordinate values
 * so that they will ease towards integral values.  This ends up smoothing the final output.
 * 
 * @param t : The value to be faded, typically in the range [0, 1].
 * @return double : The faded value.
 */ 
double PerlinNoise::fade(double t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

/**
 * @brief Linear Interpolation : This function performs linear interpolation between two values 
 * a and b. 
 * 
 * @param t : The interpolation factor, typically in the range [0, 1].
 * @param a : The first value to interpolate from.
 * @param b : The second value to interpolate to.
 * @return double : The interpolated value between a and b.
 */
double PerlinNoise::lerp(double t, double a, double b) {
    return a + t * (b - a);
}

/**
 * @brief Gradient vector 2D : This function calculates the gradient based on the hash value and 
 * the coordinates (x, y). The gradient is used to determine the direction and magnitude of the 
 * noise at that coordinate.
 * 
 * @param hash : The hash value is used to select one of the 16 possible gradient vectors.
 * @param x : Coordinate x
 * @param y : Coordinate y
 * @return double : Magnitude of the noise at that coordinate.
 */
double PerlinNoise::grad2D(int hash, double x, double y) 
{
    // Switch on first 4 bits ((15 == 0b1111) hashed value.
    switch(hash & 0xF) 
    {
        case 0x0: return  x;      // ( 1, 0)
        case 0x1: return -x;      // (-1, 0)
        case 0x2: return  y;      // ( 0, 1)
        case 0x3: return -y;      // ( 0,-1)
        case 0x4: return  x + y;  // ( 1, 1)
        case 0x5: return -x + y;  // (-1, 1)
        case 0x6: return  x - y;  // ( 1,-1)
        case 0x7: return -x - y;  // (-1,-1)
        case 0x8: return  x;      // ( 1, 0)
        case 0x9: return  y;      // ( 0, 1)
        case 0xA: return  -x;     // (-1, 0)
        case 0xB: return  -y;     // ( 0,-1)
        case 0xC: return  x + y;  // ( 1, 1)
        case 0xD: return -x + y;  // (-1, 1)
        case 0xE: return  x - y;  // ( 1,-1)
        case 0xF: return -x - y;  // (-1,-1)
        default: return 0;       // never happens
    }
}

/**
 * @brief Perlin noise with octave : This function generates Perlin noise with multiple octaves.
 * 
 * @param x : Coordinate x
 * @param y : Coordinate y
 * @param frequency : Frequency of the noise. Higher values result in more detail.
 * @param amplitude : Amplitude of the noise. Higher values result in more intensity.
 * @param octave : Number of octaves to combine. More octaves result in more complex noise.
 * @return double : The generated Perlin noise value at the given coordinates.
 */
double ALGO::PerlinNoiseWithOctave(double x, double y, double frequency, double amplitude, int octave) 
{
    double total = 0;
    double maxAmplitude = 0;
    double frequencyFactor = frequency;
    double amplitudeFactor = amplitude;

    for (int i = 0; i < octave; i++) 
    {
        total += PerlinNoise(x, y, frequencyFactor, amplitudeFactor);

        maxAmplitude += amplitudeFactor;
        frequencyFactor *= 2.0;
        amplitudeFactor *= 0.5;
    }

    return total;
}

/**
 * @brief Perlin noise algorithm : This function generates Perlin noise based on the input 
 * coordinates (x, y).
 * 
 * @param x : Coordinate x 
 * @param y : Coordinate y
 * @return double : The generated Perlin noise value at the given coordinates.
 */
double ALGO::PerlinNoise(double x, double y, double frequency, double amplitude) 
 {
    using namespace PerlinNoise;

    // The frequency is used to scale the coordinates.
    x *= frequency;
    y *= frequency;

    // DEFINE THE GRID
    // Floor of x and y : 345.345 = 345.00
    double xf = floor(x);
    double yf = floor(y);

    // Find unit cube that contain point in range of 255 : 345.0 = 89
    int UX = (int)xf & 255;
    int UY = (int)yf & 255;

    // Relative x and y in cube : 345.345 - 345.00 = 0.345 
    double xr = x - xf;
    double yr = y - yf;

    // COMPUTE FADE CURVE
    // Compute fade curves for x and y : fade(0.345) = 0.22745757841874997
    // It will be used for interpolation further down the line
    double u = fade(xr);
    double v = fade(yr);

    // COMPUTE HASH FOR GRADIENT VECTORS
    // The hash value is used to select one of the 16 possible gradient vectors
    int a = permutation(UX);     // 41
    int b = permutation(UX + 1); // 55

    int aa = permutation(a + UY);     // p[130]
    int ab = permutation(a + UY + 1); // p[132]
    int ba = permutation(b + UY);     // p[144]
    int bb = permutation(b + UY + 1); // p[145]

    // COMPUTE GRADIENTS VECTOR 
    // The gradients are calculated using the hash values and the relative coordinates
    double gradAA = grad2D(permutation(aa), xr, yr);
    double gradAB = grad2D(permutation(ab), xr, yr - 1);
    double gradBA = grad2D(permutation(ba), xr - 1, yr);
    double gradBB = grad2D(permutation(bb), xr - 1, yr - 1);

    // INTERPOLATE
    // The final noise value is obtained by interpolating between the gradients
    // using the fade curves. The lerp function is used to perform linear interpolation.
    return lerp(v, lerp(u, gradAA, gradBA), lerp(u, gradAB, gradBB)) * amplitude;
}