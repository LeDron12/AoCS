#include <iostream>
#include <vector>
#include <thread>

#include "hotel.h"

int main(int argc, char *argv[]) {
    int two_rooms = 3, three_rooms = 3;
    int women = 10, gentlemen = 10;

    Hotel *hotel = new Hotel(5);

    std::vector<Person *> persons;
    std::vector<std::thread> threads;

    if (argc < 5) {
        std::cout << "no arguments, replaced with default\n\n";
    } else {
        two_rooms = std::atoi(argv[1]);
        three_rooms = std::atoi(argv[2]);
        gentlemen = std::atoi(argv[3]);
        women = std::atoi(argv[4]);

        if (two_rooms == 0) {
            two_rooms = 3;
            std::cout << "invalid arg for 2-rooms, replaced with 3\n";
        }
        if (three_rooms == 0) {
            three_rooms = 3;
            std::cout << "invalid arg for 3-rooms, replaced with 3\n";
        }
        if (women == 0) {
            women = 10;
            std::cout << "invalid arg for women, replaced with 10\n";
        }
        if (gentlemen == 0) {
            gentlemen = 10;
            std::cout << "invalid arg for gentlemen, replaced with 10\n";
        }
        std::cout << "\n\n";
    }

    // Creating persons.
    for (int i = 0; i < women; ++i) {
        persons.push_back(new Woman(i + 1));
    }
    for (int i = 0; i < gentlemen; ++i) {
        persons.push_back(new Gentleman(women + i + 1));
    }

    // Creating rooms
    for (int i = 0; i < two_rooms; ++i) {
        hotel->addRoom(new Room(2, i + 1));
    }
    for (int i = 0; i < three_rooms; ++i) {
        hotel->addRoom(new Room(3, two_rooms + i + 1));
    }

    // Creating threads.
    for (int i = 0; i < persons.size(); ++i) {
        std::thread thread(&Hotel::tryAddPerson, hotel, persons[i]);
        threads.push_back(std::move(thread));
    }
    for (int i = 0; i < threads.size(); ++i) {
        if (threads[i].joinable()) {
            threads[i].join();
        }
    }

    delete hotel;
}
