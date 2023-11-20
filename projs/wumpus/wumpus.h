#ifndef WUMPUS_H
#define WUMPUS_H


#include "event.h"

//Wumpus Interface
class Wumpus : public Event {
    private:
    public:
    Wumpus(int x, int y) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->symbol = 'w';
        this->percept = "You smell a terrible stench";
    }

    void assert_type();
    void do_event(Player &p);
};

#endif