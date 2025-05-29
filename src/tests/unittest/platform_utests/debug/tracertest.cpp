#include <catch2/catch_test_macros.hpp>
#include <debug/Loggers.hpp>
#include <debug/Traceable.hpp>
#include <debug/Tracer.hpp>
#include <filesystem>
#include <string>
#include <sys/stat.h>

class Bidon : public Traceable
{
    public :
        std::string TraceStr() const
        {
            return "Tracer test.";
        };
};

TEST_CASE("Tracer simple message", "[platform][tracer]") 
{
const char* PathFile = "logs/simplemessage.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Tracer::Trace("Salut");
spdlog::get("trace")->flush();

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 13);
}

TEST_CASE("Tracer two message", "[platform][tracer]") 
{
const char* PathFile = "logs/twomessage.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Tracer::Trace("Salut");
Tracer::Trace("Ça va ?");
spdlog::get("trace")->flush();

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 29);
}

TEST_CASE("Tracer object", "[platform][tracer]") 
{
const char* PathFile = "logs/messagetraceable.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Traceable* t1 = new Bidon();
Tracer::Trace(*t1);
spdlog::get("trace")->flush();

delete t1;

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 20);
}