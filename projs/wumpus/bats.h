#ifndef BATS_H
#define BATS_H 

#include "event.h"

//Bats Interface
class Bats : public Event {
    private:
    public:
    Bats(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
    }

    void assert_type();
};


#endif