//
// Created by doga on 12/3/20.
//

#include "PPM.h"

PPM::PPM() {}

PPM::~PPM() {

}

const std::pair<char, int> &PPM::getTypePpm() const {
    return type_ppm;
}

void PPM::setTypePpm(const std::pair<char, int> &typePpm) {
    type_ppm = typePpm;
}

int PPM::getWidth() const {
    return width;
}

void PPM::setWidth(int width) {
    PPM::width = width;
}

int PPM::getHeight() const {
    return height;
}

void PPM::setHeight(int height) {
    PPM::height = height;
}

int PPM::getMaxColorNumber() const {
    return max_color_number;
}

void PPM::setMaxColorNumber(int maxColorNumber) {
    max_color_number = maxColorNumber;
}

Pixel **PPM::getMatrixPixels() const {
    return matrix_pixels;
}

void PPM::setMatrixPixels(Pixel **matrixPixels) {
    matrix_pixels = matrixPixels;
}
