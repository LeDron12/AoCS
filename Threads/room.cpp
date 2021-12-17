#include "room.h"

Room::Room(int capacity, int index) {
    this->index = index;
    this->capacity = capacity;
    residents.reserve(capacity);
}

void Room::tryCheckIntoTheRoom(Person *person) {
    if (residents.size() == capacity) {
        return;
    }

    if (residents.empty()) {
        checkIntoTheRoom(person);
        return;
    }

    if (residents[0]->type == person->type) {
        checkIntoTheRoom(person);
        return;
    }

    return;
}

void Room::checkIntoTheRoom(Person *person) {
    residents.push_back(person);
    person->setteled = true;
}



