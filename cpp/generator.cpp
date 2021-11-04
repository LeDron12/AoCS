//
// Created by ledron12 on 03.11.2021.
//

#include "generator.h"
#include "util.h"

Generator::Generator(FileManager *file_manager, std::string encode_type) {
    this->file_manager = file_manager;
    this->encode_type = encode_type;
    FillKeys(keys);
}

void Generator::FillKeys(std::vector<char> &vector) {
    for (int i = 0; i < 26; ++i) {
        vector.push_back('a' + i);
    }
}

void Generator::GetEncryptionKeys(std::string &variant) {
    std::map<char, char> map_cc;
    std::map<char, int> map_ci;

    if(variant.find("char-char") != std::string::npos) {
        map_cc = SwapSymbolSymbol();
    } else if(variant.find("char-shift") != std::string::npos) {
        map_cc = Caesar();
    } else if(variant.find("char-number") != std::string::npos) {
        map_ci = SwapSymbolNumber();
    } else {
        std::cout << "unknown error\n";
        return;
    }

    std::vector<std::string> vector;

    if(map_cc.size() > 0) {
        for (int i = 0; i < map_cc.size(); ++i) {
            std::string help_str;
            help_str.push_back(map_cc[keys[i]]);
            vector.push_back(help_str);
        }
    } else if (map_ci.size() > 0) {
        for (int i = 0; i < map_ci.size(); ++i) {
            vector.push_back(std::to_string(map_ci[keys[i]]));
        }
    } else {
        std::cout << "unknown error\n";
        return;
    }

    try {
        file_manager->WriteTests(vector);
    } catch (std::exception exception) {
        std::cout << exception.what();
    }
}

std::map<char, char> Generator::SwapSymbolSymbol() {
    std::map<char, char> values;

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) { // random swap.
            int x = rand();

            if (values.find(keys[(x + j) % 26]) == values.end()) {
                values[keys[i]] = keys[(x + j) % 26];
                j = 26;
            }
        }
    }

    return values;
}

std::map<char, char> Generator::Caesar() {
    std::map<char, char> values;
    int shift = rand() % 26;

    for (int i = 0; i < 26; ++i) {
        values[keys[i]] = keys[(i + shift) % 26];
    }

    return values;
}

std::map<char, int> Generator::SwapSymbolNumber() {
    std::map<char, int> values;

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) { // random swap.
            int x = rand() % 26;

            if (values.find(x) == values.end()) {
                values[keys[i]] = x;
                j = 26;
            }
        }
    }

    return values;
}
