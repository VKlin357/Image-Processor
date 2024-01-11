#include "filters.h"

Grayscale::Grayscale(Image& image) {
    const float n299 = 0.299f;
    const float n587 = 0.587f;
    const float n114 = 0.144f;

    for (int y = 0; y < image.height_; ++y) {
        for (int x = 0; x < image.width_; ++x) {
            float r = image.colors_[y * image.width_ + x].r;
            float g = image.colors_[y * image.width_ + x].g;
            float b = image.colors_[y * image.width_ + x].b;

            image.colors_[y * image.width_ + x].r = n299 * r + n587 * g + n114 * b;
            image.colors_[y * image.width_ + x].g = n299 * r + n587 * g + n114 * b;
            image.colors_[y * image.width_ + x].b = n299 * r + n587 * g + n114 * b;
        }
    }
}

Negative::Negative(Image& image) {
    for (int y = 0; y < image.height_; ++y) {
        for (int x = 0; x < image.width_; ++x) {
            image.colors_[y * image.width_ + x].r = 1 - image.colors_[y * image.width_ + x].r;
            image.colors_[y * image.width_ + x].g = 1 - image.colors_[y * image.width_ + x].g;
            image.colors_[y * image.width_ + x].b = 1 - image.colors_[y * image.width_ + x].b;
        }
    }
}
