//
// Created by ledron12 on 03.11.2021.
//
#ifndef CPP_GENERATOR_H
#define CPP_GENERATOR_H

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include "util.h"

class Generator {
public:
    std::vector<char> keys;

    FileManager *file_manager;
    std::string encode_type;

    Generator(FileManager *file_manager, std::string encode_type);

    void FillKeys(std::vector<char> &keys);

    // Making new values to encryption keys.
    void GetEncryptionKeys (std::string &variant);

    // Vales generation for random symbol-symbol swap encryption.
    std::map<char, char> SwapSymbolSymbol();

    // Values generation for Caesar's shift encryption.
    std::map<char, char> Caesar();

    // Values generation for random symbol-number swap encryption.
    std::map<char, int> SwapSymbolNumber();
};

#endif //CPP_GENERATOR_H
