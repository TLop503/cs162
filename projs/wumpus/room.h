#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
    int x;
    int y;
    Event* eve = nullptr;
public:
/**************************************************
 * Name: non-default constructor
 * Description: creates room with coordinates
 * Parameters: int coords
 * Pre-conditions: 
 * Post-conditions: room will be created with no event
 ***********************************************/
    Room(int x, int y);
	
/**************************************************
 * Name: set_event
 * Description: update event to pointer to event (used for child events)
 * Parameters: pointer to event
 * Pre-conditions: target event has been created
 * Post-conditions: room will "contain" event
 ***********************************************/
    void set_event(Event* e);

/**************************************************
 * Name: get_event
 * Description: event getter
 ***********************************************/
    Event* get_event() const;

};

#endif