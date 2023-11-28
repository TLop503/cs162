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
/**************************************************
 * Name: non-default constructor
 * Description: create wumpus with coordinates, game board limits, and a life
 * Parameters: ints for coords, maximum board size
 * Pre-conditions: 
 * Post-conditions: wumpus will be created and can move and kill or die
 ***********************************************/
    Wumpus(int x, int y, int xlim, int ylim) : Event(x,y) {
        this->x = x;
        this->y = y;
        this->xlim = xlim;
        this->ylim = ylim;
        this->symbol = 'w';
        this->percept = "You smell a terrible stench";
    }


/**************************************************
 * Name: assert_type
 * Description: debug function to assert type
 ***********************************************/
    void assert_type();

/**************************************************
 * Name: do_event
 * Description: will kill player
 * Parameters: valid player PBR
 * Pre-conditions: player wanders into wumpus room
 * Post-conditions: player.is_alive = false
 ***********************************************/
    void do_event(Player &p);

    //deprecated, unused functions that are somehow loadbearing
    //wumpus walk was old method of moving wumpus
    //special action was a polymorphic way to call wumpus walk
    void wumpus_walk();
    void special_action();

/**************************************************
 * Name: die
 * Description: kill wumpus :(
 * Parameters: 
 * Pre-conditions: 
 * Post-conditions: wumpus will be killed and removed from the board
 ***********************************************/
    void die();
    
/**************************************************
 * Name: is_alice
 * Description: getter for life
 ***********************************************/
    bool is_alive() {
        return alive;
    };
};

#endif