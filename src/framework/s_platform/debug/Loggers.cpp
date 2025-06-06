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

    if("profiler" == name)
        Loggers::profile = spdlog::basic_logger_mt(name, path, true);
    else if ("trace" == name)
        Loggers::trace = spdlog::basic_logger_mt(name, path, true);
    else if ("console" == name)
        Loggers::console = spdlog::stdout_color_mt("console");
    else
        auto custom = spdlog::basic_logger_mt(name, path, true);
}