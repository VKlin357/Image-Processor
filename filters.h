#pragma once
#include "image.h"

class Crop {
public:
    Crop(Image& image, int width, int height) : image_(image), width_(width), height_(height) {
    }
    Image image_;
    int width_;
    int height_;
};

class Grayscale {
public:
    explicit Grayscale(Image& image);
};

class Negative {
public:
    explicit Negative(Image& image);
};
