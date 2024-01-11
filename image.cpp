#include "image.h"

Color::Color() : r(0), g(0), b(0) {}
Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}
Image::Image(int width, int height) : width_(width), height_(height), colors_(std::vector<Color>(width * height)) {}
Color Image::GetColor(int x, int y) const {
    return colors_[y * width_ + x];
}

void Image::Read(const char* path) {
    std::ifstream f;
    f.open(path, std::ios::in | std::ios::binary);

    if (!f.is_open()) {
        std::cout << "impossible to open file" << std::endl;
        return;
    }

    const int file_header_size = 14;
    const int information_header_size = 40;

    unsigned char file_header[file_header_size];
    f.read(reinterpret_cast<char*>(file_header), file_header_size);

    if (file_header[0] != 'B' || file_header[1] != 'M') {
        std::cout << "path os not a bitmap image" << std::endl;
        f.close();
        return;
    }
    
    unsigned char information_header[information_header_size];
    f.read(reinterpret_cast<char*>(information_header), information_header_size);

    const size_t n5 = 5;
    const size_t n6 = 6;
    const size_t n7 = 7;
    const size_t n8 = 8;
    const size_t n9 = 9;
    const size_t n10 = 10;
    const size_t n11 = 11;
    const size_t n16 = 16;
    const size_t n24 = 24;

    width_ = information_header[4] + (information_header[n5] << n8) + (information_header[n6] << n16) + (information_header[n7] << n24);
    height_ = information_header[n8] + (information_header[n9] << n8) + (information_header[n10] << n16) + (information_header[n11] << n24);

    colors_.resize(width_ * height_);

    const size_t n255 = 255.0f;

    const int padding_amount = ((4 - (width_ * 3) % 4) % 4);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            unsigned char color[3];
            f.read(reinterpret_cast<char*>(color), 3);

            colors_[y * width_ + x].r = static_cast<float>(color[2]) / n255;
            colors_[y * width_ + x].g = static_cast<float>(color[1]) / n255;
            colors_[y * width_ + x].b = static_cast<float>(color[0]) / n255;
        }
        f.ignore(padding_amount);
    }
    f.close();

    std::cout << "file was read successfully" << std::endl;
}

void Image::Export(const char * path) const {
    std::ofstream f;
    f.open(path, std::ios::out | std::ios::binary);

    if (!f.is_open()) {
        std::cout << "impossible to open file" << std::endl;
        return;
    }
    unsigned char bmp_pad[3] = {0, 0, 0};
    const int padding_amount = ((4 - (width_ * 3) % 4) % 4);

    const int file_header_size = 14;
    const int information_header_size = 40;
    const int file_size = file_header_size + information_header_size + width_ * height_ * 3 + padding_amount * width_;

    unsigned char file_header[file_header_size];

    file_header[0] = 'B';
    file_header[1] = 'M';

    const size_t n5 = 5;
    const size_t n6 = 6;
    const size_t n7 = 7;
    const size_t n8 = 8;
    const size_t n9 = 9;
    const size_t n10 = 10;
    const size_t n11 = 11;
    const size_t n12 = 12;
    const size_t n13 = 13;
    const size_t n14 = 14;
    const size_t n15 = 15;
    const size_t n16 = 16;
    const size_t n17 = 17;
    const size_t n18 = 18;
    const size_t n19 = 19;
    const size_t n20 = 20;
    const size_t n21 = 21;
    const size_t n22 = 22;
    const size_t n23 = 23;
    const size_t n24 = 24;
    const size_t n25 = 25;
    const size_t n26 = 26;
    const size_t n27 = 27;
    const size_t n28 = 28;
    const size_t n29 = 29;
    const size_t n30 = 30;

    file_header[2] = file_size;
    file_header[3] = file_size >> n8;
    file_header[4] = file_size >> n16;
    file_header[n5] = file_size >> n24;

    file_header[n6] = 0;
    file_header[n7] = 0;

    file_header[n8] = 0;
    file_header[n9] = 0;

    file_header[n10] = file_header_size + information_header_size;
    file_header[n11] = 0;
    file_header[n12] = 0;
    file_header[n13] = 0;

    unsigned char information_header[information_header_size];

    information_header[0] = information_header_size;
    information_header[1] = 0;
    information_header[2] = 0;
    information_header[3] = 0;

    information_header[4] = width_;

    const size_t n31 = 31;
    const size_t n32 = 32;
    const size_t n33 = 33;
    const size_t n34 = 34;
    const size_t n35 = 35;
    const size_t n36 = 36;
    const size_t n37 = 37;
    const size_t n38 = 38;
    const size_t n39 = 39;

    information_header[n5] = width_ >> n8;
    information_header[n6] = width_ >> n16;
    information_header[n7] = width_ >> n24;

    information_header[n8] = height_;
    information_header[n9] = height_ >> n8;
    information_header[n10] = height_ >> n16;
    information_header[n11] = height_ >> n24;

    information_header[n12] = 1;
    information_header[n13] = 0;

    information_header[n14] = n24;
    information_header[n15] = 0;

    information_header[n16] = 0;
    information_header[n17] = 0;
    information_header[n18] = 0;
    information_header[n19] = 0;

    information_header[n20] = 0;
    information_header[n21] = 0;
    information_header[n22] = 0;
    information_header[n23] = 0;

    information_header[n24] = 0;
    information_header[n25] = 0;
    information_header[n26] = 0;
    information_header[n27] = 0;

    information_header[n28] = 0;
    information_header[n29] = 0;
    information_header[n30] = 0;
    information_header[n31] = 0;

    information_header[n32] = 0;
    information_header[n33] = 0;
    information_header[n34] = 0;
    information_header[n35] = 0;

    information_header[n36] = 0;
    information_header[n37] = 0;
    information_header[n38] = 0;
    information_header[n39] = 0;

    const size_t n255 = 255.0f;

    f.write(reinterpret_cast<char*>(file_header), file_header_size);
    f.write(reinterpret_cast<char*>(information_header), information_header_size);
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            unsigned char r = static_cast<unsigned char>(GetColor(x, y).r * n255);
            unsigned char g = static_cast<unsigned char>(GetColor(x, y).g * n255);
            unsigned char b = static_cast<unsigned char>(GetColor(x, y).b * n255);

            unsigned char color[] = {b, g, r};

            f.write(reinterpret_cast<char*>(color), 3);
        }
        f.write(reinterpret_cast<char*>(bmp_pad),  padding_amount);
    }
    f.close();

    std::cout << "file was created successfully" << std::endl;
}
