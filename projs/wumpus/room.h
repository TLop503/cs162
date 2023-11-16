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
    Room(int x, int y);
	
    void set_event(Event* e);

};

#endif