//
// Created by andrew on 03.10.2021.
//

#include <cstring>
#include <iostream>
#include "encryptingKeyNumber.h"

/// Printing data to console.
void Print(encryptionKeyNumber &keyNumber) { // Add printing to file
    std::cout << "Key = Decoded string :     ";
    for (int i = 0; i < std::strlen(keyNumber.key); ++i) {
        std::cout << keyNumber.key[i] << "--";
    }

    std::cout << "\n                           ";
    for (int i = 0; i < std::strlen(keyNumber.key); ++i) {
        std::cout << "↓  ";
    }

    std::cout << "\nValue = Encoded string :   ";
    for (int i = 0; i < std::strlen(keyNumber.key); ++i) {
        std::cout << keyNumber.number << '-';
    }

    std::cout << '\n';
    for (int i = 0; i < std::strlen(keyNumber.key) * 2 + 27; ++i) {
        std::cout << '=';
    }
    std::cout << '\n';
}