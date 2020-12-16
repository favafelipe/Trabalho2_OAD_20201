//
// Created by doga on 12/3/20.
//

#include "main.h"

int main(int argc, char * argv[]) {
    string action;
    for(int i = 0; i < argc; ++i){
        action.append(argv[i]);
    }
    cout << action;
    if (action[0] == 'c') {
        string name_file_to_open;
        name_file_to_open = "teste.ppm";
        ifstream ppm_file(name_file_to_open);

        if (ppm_file.is_open()) {
            unsigned long long int array_frequency_items[11] = {0};

            readFrequency(&ppm_file, array_frequency_items);
            ppm_file.close();

            string array_symbols_to_represent[11] = {"00", "010", "011", "1000", "1001", "1010", "1011", "1100", "1101",
                                                     "1110", "1111"};

            string array_of_symbols_CORRECT[11];
            organizeArraySymbols(array_frequency_items, array_symbols_to_represent, array_of_symbols_CORRECT);

            write_on_file(&name_file_to_open, array_of_symbols_CORRECT);

            ppm_file.close();

            cout << "\nDecompressão\n";

            decompressFunction();

            cout << "\n\n" << endl;
        } else {
            cout << "ERROR: The PPM file is not open" << endl;
        }
    } else {
        cout << endl << "Parametro num foi" << endl;
    }

    return 0;
}