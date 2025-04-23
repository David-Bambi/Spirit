#include <Algo.hpp>

#include <random>

double ALGO::RandomNoise(double max)
{
    return ((double)rand() / RAND_MAX) * max;
}