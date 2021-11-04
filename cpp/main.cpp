#include <iostream>
#include <string>
#include "util.h"
#include "generator.h"

int main(int argc, char *argv[]) {
    std::string path = "tests.txt";
    std::string command;

    FileManager *file_manager = new FileManager(path);
    Generator *generator;

    std::vector<char> keys;

    int argument;

    bool non_first = false;

    std::cout << "Tests are located in \"tests.txt\"\n\n";

    do {
        file_manager->ClearConsole();
        std::cout << "Enter one of possible commands:\n"
                     "1) \"char-char\" amount\n"
                     "2) \"char-shift\" amount\n"
                     "3) \"char-number\" amount\n"
                     "4) \"exit\"";
        std::cin >> command;

        if(command.find("exit") != std::string::npos) {
            break;
        }

        std::cin >> argument;

        generator = new Generator(file_manager, command);
        for (int i = 0; i < argument; ++i) {
            int start_time = clock();

            std::cout << "Test number " << i << ":\n\n";

            if(non_first == false) {
                generator->FillKeys(keys);
                non_first = true;
            }

            generator->GetEncryptionKeys(command);
            file_manager->PrintEncrypted(keys);

            int end_time = clock();
            std::cout << "Time spent: " << (end_time - start_time) / 1000.0 << " ms\n\n";
        }

        delete generator;

        std::cout << "press enter to continue";
        std::cin >> command;
    } while (true);

    delete file_manager;
}
