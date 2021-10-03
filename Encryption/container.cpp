//
// Created by andrew on 03.10.2021.
//

#include <cstdlib>
#include <fstream>
#include <iostream>

/// Randomizes values and fills file with them.
void RndExamples(std::ofstream& ofs){
    std::srand(205653); // use current time as seed for random generator
    int n = 10 + std::rand() % 80;

    for (int i = 0; i < n; ++i) {
        char str[1000];
        for (int j = 0; j < n; ++j) {
            str[j] = static_cast<int>('a') + std::rand() % 26;
            ofs << str[j];
        }
        ofs << '\n';

    }
}

