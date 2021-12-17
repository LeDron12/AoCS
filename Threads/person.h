#include <mutex>
#include <string>

class Person {
public:
    enum PersonType {
        woman, gentleman
    };

    std::mutex mutex;
    std::string gender;
    int index;
    bool setteled;
    PersonType type;

    Person(int index);
};

class Woman : public Person {
public:
    Woman(int index);
};

class Gentleman : public Person {
public:
    Gentleman(int index);
};