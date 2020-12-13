//
// Created by doga on 12/3/20.
//

#include "main.h"

bool testFileIsOpened(ifstream *file_to_test){
    if (file_to_test->is_open()){
        return true;
    } else{
        return false;
    }
}

void readFrequency(ifstream *file_to_read, uint *array_frequency_items){
 //   9
    if (testFileIsOpened(file_to_read) /*file_to_read->isOpen()*/){
        for (int i = 0; i < 11; ++i) {
            array_frequency_items[i] = 0;
        }
        char item;
        int item_as_number;

        while (file_to_read->get(item)){

            item_as_number = (int)item - 48;
            
            if ((int)item == 32) {
                array_frequency_items[10] += 1;
            } else if ((int)item == 10) {
                array_frequency_items[10] += 1;
            } else {
                array_frequency_items[item_as_number] += 1;
            }
        }

    } else {
        cout << "Error reading the pixels color.\n";
    }
}

int maxValue(uint *array_frequency){
    int index_max;
    int max;
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

void organizeArraySymbols(uint *array_frequency, string *array_symbols, string * array_symbols_copy){
    uint array_frequency_copy[11];

//    for (int i = 0; i < 11; ++i) {
//        cout << i << " = " << array_symbols[i] << endl;
//    }
//    cout << endl;



    for (int i = 0; i < 11; ++i) {
        array_frequency_copy[i] = array_frequency[i];
    }
    int index_max;
    pair <int, uint> array_control[11];
    for (int i = 0; i < 11; ++i) {
        index_max = maxValue(array_frequency_copy);
        array_control[i].first = index_max;
        array_control[i].second = array_frequency[index_max];
//        cout << "index_max = " << index_max;
//        cout << "->" << array_frequency[index_max];
//        cout << " | i = " << i << endl;
//        cout << " symbol_antes: " << array_symbols[index_max];
//        if ()
//        swapString(&array_symbols[i], &array_symbols[index_max]);
//        cout << " symbol_dps: " << array_symbols[index_max] << endl;
    }

    for (int i = 0; i < 11; ++i) {
        array_symbols_copy[array_control[i].first] = array_symbols[i];
        cout << array_control[i].first << "-" << array_control[i].second << "-> " << array_symbols[i] << endl;
    }

    for (int i = 0; i < 11; ++i) {
        cout << array_symbols_copy[i] << "; ";
    }

    cout<<"\n\n"<<array_symbols_copy[0]<<"\n\n";
}

void splitTypePPM(pair <char, int> *name_type, string type){
    string::size_type size_string;
    name_type->first = stoi(type, &size_string);
    name_type->second = stoi(type.substr(size_string), &size_string);
}

//void writePPMClassInFile(ofstream *file_to_write, ppm *the_image, string *array_symbols){
/*void writePPMClassInFile(PPM *the_image, string *array_symbols){
    char array_to_write = 0; //P = 0
    pair <char, int> type_split;
    splitTypePPM(&type_split, the_image->getTypePpm());
    string::size_type sz;
    int index = stoi(array_symbols[type_split.second], nullptr, type_split.second);
    cout << index << endl;
}
*/

void toggle(char *bitString, int index){

	bitString[index/8] ^= (1 << (index%8));

}

int write_bit(char *bitstring,ofstream* fileToWrite, string bits_to_write, int bit_string_index){

    for(char& c : bits_to_write) {
        if(c==1){
            toggle(bitstring,bit_string_index);
        }

        bit_string_index++;
        if(bit_string_index==7){
            (*fileToWrite)<<(*bitstring);

            bitstring[0]=0;
            bit_string_index=0;
        }
    }

    return  bit_string_index;
}

void write_on_file( string *array_of_symbols ){

    string name_file_to_open;
    name_file_to_open = "teste.ppm";
    
    ifstream ppm_file;
//    ppm_file.open(name_file_to_open);
    ppm_file.open("../"+name_file_to_open);

    ofstream fileToWrite;
    fileToWrite.open("compressed_file.bin");

    char bitstring;
    char item;
    int item_as_number;
    int bit_string_index=0;
    if( ppm_file.is_open()){
        ppm_file.get(item);

        while (ppm_file.get(item)){

            item_as_number = (int)item - 48;
            
            if ((int)item == 32) {
                //cout<<array_of_symbols[10]<<" ";
                bit_string_index=write_bit(&bitstring,&fileToWrite, array_of_symbols[10], bit_string_index);
            } else if ((int)item == 10) {
                //cout<<array_of_symbols[10]<<" ";
                bit_string_index=write_bit(&bitstring,&fileToWrite, array_of_symbols[10], bit_string_index);
            
            } else {
                //cout<<array_of_symbols[10]<<" ";
                bit_string_index=write_bit(&bitstring,&fileToWrite, array_of_symbols[item_as_number], bit_string_index);
            }
        }


    }else{

        //cout<<"\n"<<array_of_symbols[10]<<" \n";
        cout<< "errorrr\n\n";
    }


    
}

int main() {

    string name_file_to_open;
    name_file_to_open = "teste.ppm";
//    ifstream ppm_file (name_file_to_open);
    ifstream ppm_file ("../"+name_file_to_open);

    if (testFileIsOpened(&ppm_file)){
//        PPM *the_image = new PPM;
//        the_image->setTypePpm(returnTypePPM(&ppm_file));

//        cout << "PPM type = " << the_image->getTypePpm() << "\n";

        //int img_dimensions[2];
//        int *img_dimensions = (int*)malloc(sizeof(int) * 2);
//        returnDimensionsImage(&ppm_file, img_dimensions);

//        the_image->setWidth(img_dimensions[0]);
//        the_image->setHeight(img_dimensions[1]);

//        cout << "Width = " << the_image->getWidth() << "\n";
//        cout << "Height = " << the_image->getHeight() << "\n";

//        the_image->setMaxColorNumber(returnMaxColor(&ppm_file));
//        cout << "Max color value: " << the_image->getMaxColorValue() << "\n";
        uint array_frequency_items[11]/*={0}*/;

        readFrequency(&ppm_file, array_frequency_items);
        ppm_file.close();

        string array_symbols_to_represent[11] = {"00", "010", "011", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

        for (int i = 0; i < 4*11; ++i) {
//           cout << "H" << array_symbols_to_represent[i];
        }
        string array_of_symbols_CORRECT[11];
        organizeArraySymbols(array_frequency_items, array_symbols_to_represent,array_of_symbols_CORRECT);

        ppm_file.open("../"+name_file_to_open);
        if (testFileIsOpened(&ppm_file)){
            string line;
            for (int i = 0; i < 4; ++i) {
                getline(ppm_file, line);
            }
//            writePPMClassInFile(the_image, array_of_symbols_CORRECT);
        }
        
        cout<<"\n"<<array_of_symbols_CORRECT[0]<<" \n";
        write_on_file(array_of_symbols_CORRECT);
    } else {
        cout << "ERROR\n";
    }
    cout<<"\n\n"<<endl;
    return 0;
}