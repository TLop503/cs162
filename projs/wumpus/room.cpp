#include "room.h"

using namespace std;

//Room Implementation
Room::Room(int x, int y) {
    this->x = x;
    this->y = y;
}

void Room::set_event(Event* e) {
    this->eve = e;
}

Event* Room::get_event() const {
    return this->eve;
}