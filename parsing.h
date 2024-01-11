#pragma once

#include <string>
#include <string_view>
#include <map>
#include <vector>
#include <iostream>

struct Parsing {
    char* input_file;
    char* output_file;
    std::map<std::string, std::vector<std::string>> args;

    Parsing(int argc, char** argv);
};
