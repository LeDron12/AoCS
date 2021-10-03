#include <iostream>
#include "container.h"
#include "encryptionKeyValue.h"
#include <fstream>
#include <cstring>
#include <ctime>

//arg[1] - path to tests

int main(int argc, char* argv[]) {
    if(argc != 2){
        std::cout << "Incorrect input value!\n"
                     "Should be: <path/to/output.txt>";
        return 1;
    }

    std::srand(std::time(nullptr));

    container contKV; // Container with key-value encrypting data.
    char value[contKV.CAPACITY], key[contKV.CAPACITY];
    container contPS; // Container with shift by n elements encrypting data.
    char strPS[contPS.CAPACITY];
    container contKN; // Container with key-number encrypting data.
    char keyKN[contKN.CAPACITY];

    std::ofstream ofs1;
    ofs1.open(argv[1], std::ofstream::out);
    RndExamples(ofs1); /// Filling file with examples.
    ofs1.close();

    std::ifstream ifs1(argv[1]); // argv[1]
    ifs1 >> key; /// Getting first example as key.

    while (!ifs1.eof()) {

        /// Getting all containers filled with data.
        if(contKV.containerKV[contKV.lengthKV] != nullptr) {
            ifs1 >> value;

            std::strcpy(contKV.containerKV[contKV.lengthKV]->value, value);
            std::strcpy(contKV.containerKV[contKV.lengthKV]->key, key);

            std::strcpy(contPS.containerPS[contPS.lengthPS]->str, value);

            std::strcpy(contKN.containerKN[contKN.lengthKN]->key, value);
            contKN.containerKN[contKN.lengthKN]->number = 10 + std::rand() % 90 ;
        } else {
            ifs1 >> value;

            encryptionKeyValue *keyValue = new encryptionKeyValue(); /// Delete!
            std::strcpy(keyValue->value, value);
            std::strcpy(keyValue->key, key);
            contKV.containerKV[contKV.lengthKV] = keyValue;

            periodicShift *varPS = new periodicShift(); /// Delete!
            std::strcpy(varPS->str, value);
            contPS.containerPS[contPS.lengthPS] = varPS;

            encryptionKeyNumber *keyNumber = new encryptionKeyNumber(); /// Delete!
            std::strcpy(keyNumber->key, value);
            keyNumber->number = 10 + std::rand() % 90;
            contKN.containerKN[contKN.lengthKN] = keyNumber;
        }
        ++contKV.lengthKV;
        ++contPS.lengthPS;
        ++contKN.lengthKN;
    }
    ifs1.seekg(0);
    ifs1.close(); // Closing filestream.

    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TASK ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
    /// Printing data.
    for (int i = 0; i < contKV.lengthKV; ++i) {
        Print(*(contKV.containerKV[i]));
    }

    /// Clearing memory.
    for (int i = 0; i < contKV.lengthKV; ++i) {
        delete contKV.containerKV[i];
    }

    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TASK THREE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

    /// Printing data.
    for (int i = 0; i < contKN.lengthKN; ++i) {
        Print(*(contKN.containerKN[i]));
    }

    /// Clearing memory.
    for (int i = 0; i < contKN.lengthKN; ++i) {
        delete contKN.containerKN[i];
    }

    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!TASK TWO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
                 "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n";

    /// Printing data.
    for (int i = 0; i < contPS.lengthPS; ++i) {
        Print(*(contPS.containerPS[i]));
    }

    /// Clearing memory.
    for (int i = 0; i < contPS.lengthPS; ++i) {
        delete contPS.containerPS[i];
    }

    return  0;
}
