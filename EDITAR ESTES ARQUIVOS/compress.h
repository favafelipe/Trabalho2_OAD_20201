//
// Felipe Bedinotto Fava - 1801560675
// Ueslei Bervanger Brandt -
//

#ifndef TRABALHO2_OAD_20201_COMPRESS_H
#define TRABALHO2_OAD_20201_COMPRESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "decompress.h"

using namespace std;

void readFrequency(ifstream *file_to_read, unsigned long long int *array_frequency_items);

int maxValue(unsigned long long int *array_frequency);

void organizeArraySymbols(const unsigned long long int *array_frequency, string *array_symbols, string * array_symbols_copy); // array_frequency does not change, to avoid warning 'const' is used

void toggle(char *bitString, int index);

int writeBit(char *bitstring, ofstream* file_to_write, string bits_to_write, int bit_string_index);

void writeOnFile(string *name_file_to_open, string *array_of_symbols );

#endif //TRABALHO2_OAD_20201_COMPRESS_H
