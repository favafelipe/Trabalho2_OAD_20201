//
// Created by doga on 12/3/20.
//

#ifndef TRABALHO2_OAD_20201_PIXEL_H
#define TRABALHO2_OAD_20201_PIXEL_H


class Pixel {
private:
    int red;
    int green;
    int blue;
public:
    Pixel();

    virtual ~Pixel();

    int getRed() const;

    void setRed(int red);

    int getGreen() const;

    void setGreen(int green);

    int getBlue() const;

    void setBlue(int blue);
};


#endif //TRABALHO2_OAD_20201_PIXEL_H
