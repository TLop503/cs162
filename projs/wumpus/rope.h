#ifndef ROPE_H
#define ROPE_H 

#include "event.h"

//Bats Interface
class Rope : public Event {
    private:
    public:
    Rope(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->symbol = 'r';
        this->percept = "";
    }

    void assert_type();
    void do_event(Player &p);
};


#endif