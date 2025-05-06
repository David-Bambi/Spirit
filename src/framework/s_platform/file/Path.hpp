#ifndef PATH_HPP
#define PATH_HPP

#include <object/Object.hpp>
#include <string>

class Path : public Object
{
  private:
    std::string _path = STREMPTY;

  public:
    explicit Path(std::string path) : _path(path){};
    const char* PathCstr() const { return _path.c_str();};
    std::string GetPath() const { return _path;};
};

#endif