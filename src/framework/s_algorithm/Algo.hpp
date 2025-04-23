#ifndef ALGO_HPP
#define ALGO_HPP

namespace ALGO
{
    double PerlinNoise(double x, 
                       double y, 
                       double frequency=1.0, 
                       double amplitude=1.0);
    double PerlinNoiseWithOctave(double x, 
                                 double y, 
                                 double frequency=1.0, 
                                 double amplitude=1.0, 
                                 int octave=1);
    double RandomNoise(double max);
    double Normalize(double value, double min, double max);
    double Normalize(int value, int min, int max);

};

#endif