#include "parsing.h"

Parsing::Parsing(int argc, char** argv) {
    if (argc < 3) {
        throw std::runtime_error("not enough arguments or incorrect input");
    }

    input_file = argv[1];
    if (std::string(input_file).empty() || input_file[0] == '-') {
        throw std::runtime_error("not enough arguments or incorrect input");
    }

    output_file = argv[2];
    if (std::string(output_file).empty() || output_file[0] == '-') {
        throw std::runtime_error("not enough arguments or incorrect input");
    }

    std::string filter;
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            filter = std::string(argv[i]);
            args[filter] = {};
        } else {
            args[filter].emplace_back(argv[i]);
        }
    }
}
