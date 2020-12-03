//
// Created by doga on 12/3/20.
//

#ifndef TRABALHO2_OAD_20201_MAIN_H
#define TRABALHO2_OAD_20201_MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include "PPM.h"

using namespace std;

bool testFileIsOpened(ifstream *file_to_test);

pair <char, int> returnTypePPM(ifstream *file_to_read);

void splitDimensions(int *array_dimensions, string dimensions);

void returnDimensionsImage(ifstream *file_to_read, int *array_dimensions);

int returnMaxColor(ifstream *file_to_read);

void readFrequency(ifstream *file_to_read, uint *array_frequency_items);

int maxValue(uint *array_frequency);

string *organizeArraySymbols(uint *array_frequency, string *array_symbols);

void splitTypePPM(pair <char, int> *name_type, string type);

void writePPMClassInFile(ppm *the_image, string *array_symbols);


#endif //TRABALHO2_OAD_20201_MAIN_H
