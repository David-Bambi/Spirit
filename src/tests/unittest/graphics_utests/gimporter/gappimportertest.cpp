#include <catch2/catch_test_macros.hpp>
#include <gapp/Gapp.hpp>
#include <gimporter/GJsonImporter.hpp>
#include <memory>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>

TEST_CASE("ImportGapp", "[graphics][import]") 
{
    std::shared_ptr<Gapp> Gapp = GJsonImporter::ImportGapp("program1");
    REQUIRE(Gapp != nullptr);
}

TEST_CASE("ImportGappNotValid", "[graphics][import]") 
{
std::shared_ptr<Gapp> Gapp;
REQUIRE_THROWS_AS(Gapp = GJsonImporter::ImportGapp("program2"), std::runtime_error);
REQUIRE(Gapp == nullptr);
}

TEST_CASE("ImportJsonNotValid", "[graphics][import]") 
{
std::shared_ptr<Gapp> Gapp;
REQUIRE_THROWS_AS(Gapp = GJsonImporter::ImportGapp("program3"), nlohmann::json::exception);
REQUIRE(Gapp == nullptr);
}