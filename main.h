//
// Created by doga on 12/3/20.
//

#ifndef TRABALHO2_OAD_20201_MAIN_H
#define TRABALHO2_OAD_20201_MAIN_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readFrequency(ifstream *file_to_read, unsigned long long int *array_frequency_items);

int maxValue(unsigned long long int *array_frequency);

void organizeArraySymbols(const unsigned long long int *array_frequency, string *array_symbols, string *array_symbols_copy);

void toggle(char *bitString, int index);

#endif //TRABALHO2_OAD_20201_MAIN_H
