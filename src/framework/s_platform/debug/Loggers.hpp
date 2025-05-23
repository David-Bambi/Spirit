#ifndef LOGGERS_HPP
#define LOGGERS_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Loggers
{
    inline auto trace = spdlog::basic_logger_mt("trace", "logs/trace.log", true);
    inline auto profile = spdlog::basic_logger_mt("profile", "logs/profile.log", true);

    static void Init(const char* name, const char* path)
    {
        auto logger = spdlog::get(name);

        if (logger)
            spdlog::drop(name);

        auto trace = spdlog::basic_logger_mt(name, path, true);
    };
};



#endif
