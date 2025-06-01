#ifndef LOGGERS_HPP
#define LOGGERS_HPP

#include "spdlog/sinks/stdout_color_sinks.h"
#include <memory>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

namespace Loggers
{
std::shared_ptr<spdlog::logger> Ltrace = spdlog::basic_logger_mt("trace", "logs/trace.log", true);
std::shared_ptr<spdlog::logger> profile =
    spdlog::basic_logger_mt("profiler", "logs/profile.log", true);
std::shared_ptr<spdlog::logger> console = spdlog::stdout_color_mt("console");

void Init(const char* name, const char* path)
{
    auto logger = spdlog::get(name);

    if (logger)
        spdlog::drop(name);

    auto trace = spdlog::basic_logger_mt(name, path, true);
};
}; // namespace Loggers

#endif
