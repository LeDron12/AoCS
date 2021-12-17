#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "room.h"

class Hotel {
public:
    std::vector<Room *> rooms;

    Hotel(int capacity);

    void addRoom(Room *room);

    void tryAddPerson(Person *person);
};

