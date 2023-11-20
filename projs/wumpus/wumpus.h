#ifndef WUMPUS_H
#define WUMPUS_H


#include "event.h"

//Wumpus Interface
class Wumpus : public Event {
    private:
        bool alive = true;
        int xlim;
        int ylim;
    public:
    Wumpus(int x, int y, int xlim, int ylim) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->xlim = xlim;
        this->ylim = ylim;
        this->symbol = 'w';
        this->percept = "You smell a terrible stench";
    }

    void assert_type();
    void do_event(Player &p);
    void wumpus_walk();
    void special_action();
    
    bool is_alive() {
        return alive;
    };
};

#endif