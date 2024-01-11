#pragma once

#include <iostream>
#include <fstream>
#include <vector>

struct Color {
    float r, g, b;

    Color();
    Color(float r, float g, float b);
};

class Image {
public:
    Image(int width, int height);
    Color GetColor(int x, int y) const;

    void Read(const char* path);
    void Export(const char* path) const;

    int width_;
    int height_;
    std::vector<Color> colors_;
};
