#ifndef DEBUGHANDLER_HPP
#define DEBUGHANDLER_HPP

#include <execinfo.h>
#include <signal.h>
#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <spdlog/spdlog.h>

namespace DebugHandler
{
void CrashHandler(int sig)
{
    void* array[50];
    size_t size = backtrace(array, 50);
    char** messages = backtrace_symbols(array, size);

    std::ofstream out("logs/crash_log.txt");
    out << "Application crashed with signal " << sig << "\n";
    out << "Call stack:\n";

    for (size_t i = 0; i < size; ++i)
    {
        out << messages[i] << "\n";
    }

    auto profilerLogger = spdlog::get("profiler");
    if (profilerLogger)
        profilerLogger->flush();

    auto traceLogger = spdlog::get("trace");
    if (traceLogger)
        traceLogger->flush();

    free(messages);
    out.close();

    std::exit(1);
};

void SetupCrashHandler()
{
    signal(SIGSEGV, CrashHandler); // Segmentation fault
    signal(SIGABRT, CrashHandler); // Abort signal
    signal(SIGFPE, CrashHandler); // Floating point exception
    signal(SIGILL, CrashHandler); // Illegal instruction
    signal(SIGBUS, CrashHandler); // Bus error
};
}; // namespace DebugHandler

#endif