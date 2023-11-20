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
        this->symbol = 'b';
        this->percept = "You hear wings flapping.";
    }

    void assert_type();
};


#endif