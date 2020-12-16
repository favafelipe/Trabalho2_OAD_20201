//
// Felipe Bedinotto Fava - 1801560675
// Ueslei Bervanger Brandt -
//

#include "compress.h"

void readFrequency(ifstream *file_to_read, unsigned long long int *array_frequency_items){

    if (file_to_read->is_open()){
        char item;
        int item_as_number;
        file_to_read->get(item); // read p and not count it
        while (file_to_read->get(item)){
            item_as_number = (int)item - 48;
            if (((int)item == 32) || ((int)item == 10)) {
                array_frequency_items[10] += 1;
            } else {
                array_frequency_items[item_as_number] += 1;
            }
        }

    } else {
        cout << "Error reading the file content.\n";
    }
}

int maxValue(unsigned long long int *array_frequency){
    int index_max;
    unsigned long long int max;
    max = 0;
    for (int i = 0; i < 11; ++i) {
        if (array_frequency[i] > max){
            max = array_frequency[i];
            index_max = i;
        }
    }
    array_frequency[index_max] = 0;
    return index_max;
}

void organizeArraySymbols(const unsigned long long int *array_frequency, string *array_symbols, string * array_symbols_copy){ // array_frequency does not change, to avoid warning 'const' is used
    unsigned long long int array_frequency_copy[11];

    for (int i = 0; i < 11; ++i) {
        array_frequency_copy[i] = array_frequency[i];
    }
    int index_max;
    pair <int, uint> array_control[11];
    for (auto & i : array_control) { // *Range-based loop* foreach do c++ (must have the & to be a pointer)
        index_max = maxValue(array_frequency_copy);
        i.first = index_max;
        i.second = array_frequency[index_max];
    }

    for (int i = 0; i < 11; ++i) {
        array_symbols_copy[array_control[i].first] = array_symbols[i];
        cout << array_control[i].first << "-" << array_control[i].second << "-> " << array_symbols[i] << endl;
    }
}


void toggle(char *bitString, int index){

    bitString[index/8] ^= (1 << (index%8));

}

int writeBit(char *bitstring, ofstream* file_to_write, string bits_to_write, int bit_string_index){

    for(char & c : bits_to_write) { // foreach
        if(c == '1'){
            toggle(bitstring,bit_string_index);
        }
        bit_string_index++;
        if(bit_string_index==7){
            (*file_to_write)<<(*bitstring);
            // for (int l = 0; l < 8; l++)
            // {
            //     printf("%d", getBit(bitstring, l));
            // }
            // cout << endl;
            bitstring[0] = 0;
            bit_string_index = 0;
        }
    }

    return  bit_string_index;
}

void writeOnFile(string *name_file_to_open, string *array_of_symbols ){

    ifstream ppm_file;
    ppm_file.open(*name_file_to_open);

    ofstream file_to_write;
    file_to_write.open("compressed_" + *name_file_to_open + ".bin");

    char bitstring = 0;
    char item;
    int item_as_number;
    int bit_string_index = 0;
    if( ppm_file.is_open()){
        ppm_file.get(item); // Read the 'P' from file, but not compress it in the final file. 'P' is erased in compression
        for(int i=0;i<10;i++){
            file_to_write << array_of_symbols[i] << " ";
        }
        file_to_write << array_of_symbols[10] << endl;
        cout << "The file is being compressed, please wait." << endl;
        while (ppm_file.get(item)){
            item_as_number = (int)item - 48;

            if (((int)item == 32) || ((int)item == 10)) {
                bit_string_index = writeBit(&bitstring, &file_to_write,array_of_symbols[10], bit_string_index);
            } else {
                bit_string_index = writeBit(&bitstring, &file_to_write, array_of_symbols[item_as_number], bit_string_index);
            }
        }
        if (bit_string_index < 8 && bit_string_index != 0){
            file_to_write << bitstring;
            // for (int l = 0; l < 8; l++)
            // {
            //     printf("%d", getBit(&bitstring, l));
            // }
            // cout << endl;
        }
        cout << "The file was compressed successully." << endl;
    }else{
        cout<< "Error writing bits." << endl;
    }
}