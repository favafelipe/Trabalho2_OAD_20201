//
// Created by doga on 12/13/20.
//

#include "decompress.h"

int getBit(char *bit_string, int index){

    return 1 & (bit_string[index / 8] >> (index % 8));
}

void decompressFunction(){

    ifstream compressed_file("compressed_file.bin");
    ofstream new_image;

    new_image.open("new_image.txt");

    string line, bit_string;
    char x;
    int k;
    map<int,string> dictionary;
 
    if(compressed_file.is_open()){

        //lê a primeira linha do arquivo comprimido e coloca as sequecias de bits em uma estrutura de dicionario
        for(int i=0; i< 11 ; i++){
            compressed_file>>line;
            cout<<line<<" ";
            dictionary.insert( pair<int,string>(i, line) );

        }

        //escreve o "P" no começo do arquivo
        new_image<<"P";
        cout<<"\nP";
        
        //le cada char do arquivo comprimido 
        while(compressed_file.get(x)){
            

            //le os bits do char  
            for(int i=0; i<8; i++){
                bit_string[k]=getBit(&x,i);
                
                //verifica se a sequecia de bit ja lidas esta no dicionario e se estiver 
                //printa o char equivalente no arquivo e limpa a bit string
                for (auto &it : dictionary){
                    if (it.second == bit_string){
                        if( it.first== 10){
                            //cout<< " ";
                            new_image<<" ";
                        }else{
                            //cout<<it.first;
                            new_image << it.first;
                        }
                        bit_string.clear();
                        k=0;
                        
                    }
                }
            }
        }
    new_image.close();
    compressed_file.close();
    
    }
}