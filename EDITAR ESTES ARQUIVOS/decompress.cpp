//
// Felipe Bedinotto Fava - 1801560675
// Ueslei Bervanger Brandt -
//

#include "decompress.h"

int getBit(const char *bitString, int index){
    return 1 & (bitString[index / 8] >> (index % 8));
}

void decompressFile(ifstream *bin_file, string *name_file)
{
    ofstream new_image;

    new_image.open("new_" + *name_file + ".ppm");

    string representation_code;
    vector <int> vector_bits;
    char x;
    // int k;
    // k = 0;
    unordered_map <string, int> dictionary;
    unordered_map <string, int>::const_iterator code_found_in_dictionary;
    string code;

    if (bin_file->is_open())
    {

        //lê a primeira linha do arquivo comprimido e coloca as sequecias de bits em uma estrutura de dicionario
        for (int i = 0; i < 11; i++)
        {
            *bin_file >> representation_code;
            // cout << representation_code << " ";
            dictionary.emplace(representation_code, i);
        }

        //escreve o "P" no começo do arquivo
        new_image << "P";
        cout << "The file is being decompressed, please wait." << endl;
        //le cada char do arquivo comprimido
        while (bin_file->get(x))
        {
            // cout << "X value = " << x << endl;
            //le os bits do char
            for (int i = 0; i < 8; i++)
            {
                // vector_bits.push_back(getBit(&x, i));

                code.append(to_string(getBit(&x, i)));

                code_found_in_dictionary = dictionary.find(code);
                if (code_found_in_dictionary != dictionary.end())
                {
                    if (code_found_in_dictionary->second == 10)
                    {
                        new_image << " ";
                        // cout << "space" << endl;
                    }
                    else
                    {
                        // cout << "CODE" << code_found_in_dictionary->second << endl;
                        new_image << code_found_in_dictionary->second;
                    }
                    code.erase(code.begin(), code.end());
                    // vector_bits.erase(vector_bits.begin(), vector_bits.end());
                    code.clear();
                    // vector_bits.clear();
                }
                // for (int &j : vector_bits)
                // {
                    // code.append(to_string(j));
                    
                    // cout << "CODE = " << code << endl;
                    
                    
                // }

                //verifica se a sequecia de bit ja lidas esta no dicionario e se estiver
                //printa o char equivalente no arquivo e limpa a bit string
                // for (auto &it : dictionary)
                // {
                //     if (it.second == vector_bits)
                //     {
                //         if (it.first == 10)
                //         {
                //             //cout<< " ";
                //             new_image << " ";
                //         }
                //         else
                //         {
                //             //cout<<it.first;
                //             new_image << it.first;
                //         }
                //         vector_bits.clear();
                //         k = 0;
                //     }
                // }
                // k += 1;
                // vector_bits.clear();
            }
        }
    }
    new_image.close();
    bin_file->close();
    cout << "The file was decompressed successully." << endl;
}