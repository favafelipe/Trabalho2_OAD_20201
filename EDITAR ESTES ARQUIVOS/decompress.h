//
// Felipe Bedinotto Fava - 1801560675
// Ueslei Bervanger Brandt -
//

#ifndef TRABALHO2_OAD_20201_DECOMPRESS_H
#define TRABALHO2_OAD_20201_DECOMPRESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int getBit(const char *bitString, int index);

void decompressFile(ifstream *bin_file, string *name_file);

#endif //TRABALHO2_OAD_20201_DECOMPRESS_H
