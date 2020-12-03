//
// Created by doga on 12/3/20.
//

#include "Pixel.h"

Pixel::Pixel() {}

Pixel::~Pixel() {

}

int Pixel::getRed() const {
    return red;
}

void Pixel::setRed(int red) {
    Pixel::red = red;
}

int Pixel::getGreen() const {
    return green;
}

void Pixel::setGreen(int green) {
    Pixel::green = green;
}

int Pixel::getBlue() const {
    return blue;
}

void Pixel::setBlue(int blue) {
    Pixel::blue = blue;
}
