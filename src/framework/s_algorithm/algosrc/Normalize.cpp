#include <Algo.hpp>
#include <iostream>
double ALGO::Normalize(double value, double max, double min)
{
    value = (value - min) / (max - min);

    return value;
}

double ALGO::Normalize(int value, int max, int min)
{   
    double valuedouble = (double)value;
    double maxdouble = (double)max;
    double mindouble = (double)min;
    
    return (valuedouble - mindouble) / (maxdouble - mindouble);
}