//
// Created by ledron12 on 03.11.2021.
//
#ifndef CPP_UTIL_H
#define CPP_UTIL_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class FileManager {
public:
    std::string path_tests;

    std::ofstream tests_write;
    std::ifstream tests_read;

    FileManager(std::string path_tests);

    // Writes generated tests from "text" to file.
    void WriteTests(const std::vector<std::string> &text);

    // Reads all tests from file and returns vector of tests.
    std::vector<std::string> ReadTests();

    // Prints final encryption.
    void PrintEncrypted(std::vector<char> &keys);

    // Clears console.
    void ClearConsole();
};

#endif //CPP_UTIL_H
