#include <debug/Loggers.hpp>

std::shared_ptr<spdlog::logger> Loggers::trace =
    spdlog::basic_logger_mt("trace", "logs/trace.log", true);
std::shared_ptr<spdlog::logger> Loggers::profile =
    spdlog::basic_logger_mt("profiler", "logs/profile.log", true);
std::shared_ptr<spdlog::logger> Loggers::console = spdlog::stdout_color_mt("console");

void Loggers::Init(const char* name, const char* path)
{
    auto logger = spdlog::get(name);

    if (logger)
        spdlog::drop(name);

    auto trace = spdlog::basic_logger_mt(name, path, true);
}