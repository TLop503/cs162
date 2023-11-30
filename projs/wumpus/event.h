#ifndef EVENT_H
#define EVENT_H 

#include <string>

#include "player.h"

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	int x;
    int y;
    char symbol = '?';
    string percept = "default percept";


public:
/**************************************************
 * Name: default constructor
 * Description: creates event with default values seen above
 * Parameters: no
 * Pre-conditions: 
 * Post-conditions: event will be created
 ***********************************************/
    Event();

/**************************************************
 * Name: non-default constructor
 * Description: updates coordinates of event
 * Parameters: x, y -- coords (int)
 * Pre-conditions: 
 * Post-conditions: event will have matching coordinates. note this doesn't actually impact it's location, but
 * makes it easier to asses even location to prevent from traversing the entire grid each turn
 ***********************************************/
    Event(int x, int y);
    
/**************************************************
 * Name: assert_type
 * Description: debug function to verify event is default
 ***********************************************/
    virtual void assert_type();

/**************************************************
 * Name: get_symbol
 * Description: returns symbol of event for grid printing
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns symbol
 ***********************************************/
	char get_symbol() const;


/**************************************************
 * Name: print_percept
 * Description: prints the percept string of the event to inform player
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: couts percept
 ***********************************************/
    void print_percept() const;

/**************************************************
 * Name: pure virtual do_event()
 * Description: to be overwritten by childern with unique functionality
 * Parameters: existing player
 * Pre-conditions: child is initialized and overwrites this
 * Post-conditions: not to be used
 ***********************************************/
    virtual void do_event(Player &p) = 0;

/**************************************************
 * Name: deprecated wumpus function
 * Description: was used to check if wumpus was alive, but has been replaced. kept for thuroughness.
 ***********************************************/
    bool is_alive(); //for wumpus
	
//Getters
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }

//Setters
    void set_x(int x) {
        this->x = x;
    }
    void set_y(int y) {
        this->y = y;
    }

/**************************************************
 * Name: used for events with unique extra functions, such as the wumpus walking around
 * Description: virtual function to be overwritten by childern
 ***********************************************/
    virtual void special_action();
};
#endif