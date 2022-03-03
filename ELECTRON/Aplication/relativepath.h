#pragma once
#include <filesystem>


std::string rp = std::filesystem::path(std::filesystem::current_path()).string();
std::string relpath = rp.substr(0, rp.find("out"));
#define RELPATH relpath