//
// Created by andrew on 03.10.2021.
//

#include <cstring>
#include <iostream>
#include "periodicShift.h"

/// Printing data to console.
void Print(periodicShift &strPS) {
    strPS.shift = std::rand() % std::strlen(strPS.str);

    std::cout << "Key = Decoded string :     ";
    for (int i = 0; i < std::strlen(strPS.str); ++i) {
        std::cout << strPS.str[i] << '-';
    }

    std::cout << "\nShift = " << strPS.shift << "                 ";

    for (int i = 0; i < std::strlen(strPS.str); ++i) {
        std::cout << "↓ ";
    }

    std::cout << "\nValue = Encoded string :   ";
    for (int i = 0; i < std::strlen(strPS.str); ++i) {
        std::cout << strPS.str[(i + strPS.shift) %  std::strlen(strPS.str)] << '-';
    }

    std::cout << '\n';
    for (int i = 0; i < std::strlen(strPS.str) * 2 + 27; ++i) {
        std::cout << '=';
    }
    std::cout << '\n';
}
