#ifndef LOGGERS_HPP
#define LOGGERS_HPP

#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

class Loggers
{
public :
    static std::shared_ptr<spdlog::logger> trace;
    static std::shared_ptr<spdlog::logger> profile;
    static std::shared_ptr<spdlog::logger> console;
    
    static void Init(const char* name, const char* path);
};

#endif
