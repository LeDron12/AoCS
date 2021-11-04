//
// Created by ledron12 on 03.11.2021.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "util.h"

FileManager::FileManager(std::string path_tests) {
    this->path_tests = path_tests;
}

void FileManager::WriteTests(const std::vector<std::string> &text) {

    // Opening and clearing file from previous tests.
    tests_write.open(path_tests, std::ofstream::trunc);
//    if(!tests_write.is_open()) {
//        throw "cant open file with tests!";
//    }

    for (int i = 0; i < text.size(); ++i) {
        tests_write << text[i] << " ";
    }

    tests_write.close();
//    std::cout << "tests have been upgraded\n";
}

std::vector<std::string> FileManager::ReadTests() {
    std::string str;
    std::vector<std::string> ans;

    tests_read.open(path_tests);
//    if(!tests_read.is_open()) {
//        throw "cant open file with answers";
//    }

    while (!tests_read.eof()) {
        tests_read >> str;
        ans.push_back(str);
    }

    tests_read.close();
//    std::cout << "test have been read\n";

    return ans;
}

void FileManager::PrintEncrypted(std::vector<char> &keys) {
    std::vector<std::string> text;
    try{
        text = FileManager::ReadTests();
    } catch (std::exception exception) {
        std::cout << exception.what();
    }

    std::cout << "before: ";
    for (int i = 0; i < keys.size(); ++i) {
        std::cout << keys[i] << " - ";
    }
    std::cout << '\n';
    std::cout << "after:  ";
    for (int i = 0; i < text.size() - 1; ++i) {
        if(text[i].find("") != std::string::npos) {
            std::cout << text[i] << " - ";
        }
    }
//    std::cout << "\n\n";
//    std::cout << "~~~~~~~~";
//    for (int i = 0; i < text.size() * 4; ++i) {
//        std::cout << '~';
//    }
    std::cout << "\n";
}

void FileManager::ClearConsole() {
        std::cout << "\x1B[2J\x1B[H";
}