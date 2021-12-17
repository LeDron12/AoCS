#include <vector>
#include <mutex>

#include "person.h"

class Room {
public:
    std::mutex mutex;
    std::vector<Person *> residents;

    int index;
    int capacity;

    Room(int capacity, int index);

    void tryCheckIntoTheRoom(Person *person);

    void checkIntoTheRoom(Person *person);
};
