//
// Felipe Bedinotto Fava - 1801560675
// Ueslei Bervanger Brandt - 
//

// RODAR TRABALHO(aparece erro se ./executable nao existir, mas nao tem problema, pois o make cria)
// (make clean && make) || make
// ./executable -c arquivo.ppm

#include "main.h"

int main(int argc, char * argv[]) {
    cout << endl;
    string action;
    string name_file;
    if (argv[1]) // Test if the first argument(the action to be executed, compress or decompress) was passed
    {
        if (argv[2]) // Test if the the name of the file to be opened was passed
        {
            action = argv[1];
            name_file = argv[2];

            if (action[0] == 'd' || action[1] == 'd') // Test if the action refers to decompression
            {
                if (ifstream(name_file)) // Verify if the file exist in the current directory
                {
                    ifstream bin_file(name_file);
                    if (bin_file.is_open()) // Test if the file is really open
                    {
                        cout << "Working in progress." << endl;
                        decompressFile(&bin_file, &name_file);
                    }
                    else
                    {
                        cout << "ERROR 02: Bin file could not be opened, please check if the name is correct." << endl;
                    }
                }
                else
                {
                    cout << "ERROR 01: File does not exist in this directory." << endl;
                }
            }
            else if (action[0] == 'c' || action[1] == 'c') // Test if the action is to compress a file
            {
                if (ifstream(name_file)) // Verify if the file exist in the current directory
                {
                    ifstream ppm_file(name_file);

                    if (ppm_file.is_open()) // Test if the file is really open
                    {
                        unsigned long long int array_frequency_items[11] = {0}; // Array responsable for keep the frequency(number of times it appears) of an element in the file 
                        /*
                        The values in the array refer to it's position
                        For example: the number in the position 0 of the array, is the frequency of the number 0
                        The last position of the array(position 10), is the frequency of the 'space' character
                        And YES, the file decompressed become a line, but this format works as a PPM file.
                        */                        

                        readFrequency(&ppm_file, array_frequency_items);

                        ppm_file.close(); // Once the file was read, the 'array_frequency_items' has the frequency of the elements

                        string array_symbols_to_represent[11] = {"00", "010", "011", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"}; // Codes to become the bit representation

                        string array_of_symbols_CORRECT[11];
                        organizeArraySymbols(array_frequency_items, array_symbols_to_represent, array_of_symbols_CORRECT); // This function sync the symbols with the frequencies

                        writeOnFile(&name_file, array_of_symbols_CORRECT); // Write the bits in the file
                    }
                    else
                    {
                        cout << "ERROR 03: PPM file could not be opened, please check if the name is correct." << endl;
                    }
                }
                else
                {
                    cout << "ERROR 01: File does not exist in this directory." << endl;
                }
            }
            else
            {
                cout << "Invalid action, please try one of these:" << endl;
                cout << "To compress:\tc" << endl
                     << "\t\t-c" << endl
                     << "\t\tcompress" << endl
                     << "\t\tcompressionar" << endl;

                cout << "To decompress:\td" << endl
                     << "\t\t-d" << endl
                     << "\t\tdecompress" << endl
                     << "\t\tdescompressionar" << endl;
            }
        }
        else
        {
            cout << "No file name passed, please try again." << endl;
            cout << "\tExamples of correct use: " << endl
                 << "\t\t./executable -c test.ppm" << endl
                 << "\t\t./executable -d compressed_file.bin" << endl;
        }
        
    }
    else
    {
        cout << "No action passed, please try again." << endl;
        cout << "\tExamples of correct use: " << endl
             << "\t\t./executable -c test.ppm" << endl
             << "\t\t./executable -d compressed_file.bin" << endl;
    }
    
    cout << endl;
    return 0;
}