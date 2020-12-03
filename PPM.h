//
// Created by doga on 12/3/20.
//

#ifndef TRABALHO2_OAD_20201_PPM_H
#define TRABALHO2_OAD_20201_PPM_H

#include <string>
#include "Pixel.h"

class PPM {
private:
    std::pair <char, int> type_ppm;
    int width;
    int height;
    int max_color_number;
    Pixel **matrix_pixels;
public:
    PPM();

    virtual ~PPM();

    const std::pair<char, int> &getTypePpm() const;

    void setTypePpm(const std::pair<char, int> &typePpm);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    int getMaxColorNumber() const;

    void setMaxColorNumber(int maxColorNumber);

    Pixel **getMatrixPixels() const;

    void setMatrixPixels(Pixel **matrixPixels);
};


#endif //TRABALHO2_OAD_20201_PPM_H
