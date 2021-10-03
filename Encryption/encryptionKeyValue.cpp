//
// Created by andrew on 03.10.2021.
//

#include <cstring>
#include <iostream>
#include "encryptionKeyValue.h"

/// Printing data to console.
void Print(encryptionKeyValue &keyValue) { // Add printing to file
    std::cout << "Key = Decoded string :     ";
    for (int i = 0; i < std::strlen(keyValue.key); ++i) {
        std::cout << keyValue.key[i] << '-';
    }

    std::cout << "\n                           ";
    for (int i = 0; i < std::strlen(keyValue.key); ++i) {
        std::cout << "↓ ";
    }

    std::cout << "\nValue = Encoded string :   ";
    for (int i = 0; i < std::strlen(keyValue.value); ++i) {
        std::cout << keyValue.value[i] << '-';
    }

    std::cout << '\n';
    for (int i = 0; i < std::strlen(keyValue.value) * 2 + 27; ++i) {
        std::cout << '=';
    }
    std::cout << '\n';
}
