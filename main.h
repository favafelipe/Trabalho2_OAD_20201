//
// Created by doga on 12/3/20.
//

#ifndef TRABALHO2_OAD_20201_MAIN_H
#define TRABALHO2_OAD_20201_MAIN_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool testFileIsOpened(ifstream *file_to_test);

void splitDimensions(int *array_dimensions, string dimensions);

void readFrequency(ifstream *file_to_read, uint *array_frequency_items);

int maxValue(uint *array_frequency);

void organizeArraySymbols(uint *array_frequency, string *array_symbols, string *array_symbols_copy);

void splitTypePPM(pair <char, int> *name_type, string type);

#endif //TRABALHO2_OAD_20201_MAIN_H
