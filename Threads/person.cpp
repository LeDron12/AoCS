#include "person.h"

Person::Person(int index) {
    this->index = index;
    setteled = false;
}

Woman::Woman(int index) : Person(index) {
    type = woman;
    gender = "woman";
    setteled = false;
}

Gentleman::Gentleman(int index) : Person(index) {
    type = gentleman;
    gender = "man";
    setteled = false;
}
