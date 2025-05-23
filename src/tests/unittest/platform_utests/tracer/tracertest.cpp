#include <catch2/catch_test_macros.hpp>

#include <object/Object.hpp>
#include <debug/Tracer.hpp>
#include <debug/Loggers.hpp>
#include <iostream>
#include <filesystem>
#include <sys/stat.h>

class Bidon : public Object
{};

TEST_CASE("Tracer simple message", "[TraceMessage]") 
{
const char* PathFile = "logs/simplemessage.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Tracer::Trace("Salut");
spdlog::get("trace")->flush();

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 13);
}

TEST_CASE("Tracer two message", "[TraceMessage2]") 
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

TEST_CASE("Tracer object", "[TraceMessageObject]") 
{
const char* PathFile = "logs/messageobject.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Object* obj = new Object();
Tracer::Trace(*obj);
spdlog::get("trace")->flush();

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 55);
}

TEST_CASE("Tracer object bidon", "[TraceMessageObjectBidon]") 
{
Object::NextSeqNo = 0;

const char* PathFile = "logs/messageobjectBidon.trc";
Loggers::Init("trace", PathFile);
spdlog::get("trace")->set_pattern("[%l] %v");

Object* obj = new Bidon();
Tracer::Trace(*obj);
spdlog::get("trace")->flush();

REQUIRE(std::filesystem::exists(PathFile));
REQUIRE(std::filesystem::file_size(PathFile) == 54);
}