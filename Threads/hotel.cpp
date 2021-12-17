#include "hotel.h"

Hotel::Hotel(int capacity) {
    std::srand(std::time(nullptr));
    rooms.reserve(capacity);
}

void Hotel::addRoom(Room *room) {
    rooms.push_back(room);
}

void Hotel::tryAddPerson(Person *person) {
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 200));

    person->mutex.lock();
    for (auto room : rooms) {
        room->mutex.lock();
        room->tryCheckIntoTheRoom(person);

        if (person->setteled) {
            std::cout << person->gender << " " << person->index << " got "
                      << room->capacity << " slotted room " << room->index << "\n";
            room->mutex.unlock();
            person->mutex.unlock();
            return;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 200));
        room->mutex.unlock();
    }
    std::cout << person->gender << " " << person->index
              << " didn't get any room\n";

    person->mutex.unlock();
}
