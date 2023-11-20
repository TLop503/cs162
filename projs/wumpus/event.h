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
    Event();
    Event(int x, int y);
    
    virtual void assert_type();
	char get_symbol() const;
    void print_percept() const;

    virtual void do_event(Player &p);
	
};
#endif