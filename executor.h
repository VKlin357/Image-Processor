#pragma once
#include "filters.h"
#include <vector>
#include <string>
#include <map>

void Executor(Image& image, std::map<std::string, std::vector<std::string>>& args) {
    for (const auto& filter : args) {
        if (filter.first == "-neg") {
            Negative neg(image);
        } else if (filter.first == "-gs") {
            Grayscale gs(image);
        } else if (filter.first == "-crop") {
            if (filter.second.size() < 2) {
                throw std::runtime_error("not enough arguments or incorrect input for -crop");
            }
            int width = std::stoi(filter.second[0]);
            int height = std::stoi(filter.second[1]);
            Crop crop(image, width, height);
        } else {
            throw std::runtime_error("not enough arguments or incorrect input");
        }
    }
}
