#include "event.h"

#include <iostream>

using namespace std;

//Event Implementation
Event::Event(int x, int y) {
    this->x = x;
    this->y = y;
}

Event::Event() {

}

void Event::assert_type() {
    cout << "I'm a generic event" << endl;
}