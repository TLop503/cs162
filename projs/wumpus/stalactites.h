#ifndef STALACTITES_H
#define STALACTITES_H

#include "event.h"

//Stalactites Interface
class Stalactites : public Event {
    private:
    public:
    Stalactites(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
    }

    void assert_type();
};

#endif