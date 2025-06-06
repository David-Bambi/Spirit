#include <mesh/Vertices.hpp>

#include <string/ToStr.hpp>

std::string Vertices::TraceStr() const 
{
    return ToStr::Vec(_indexs, 3);
}