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

    virtual void do_event(Player &p) = 0;
    bool is_alive(); //for wumpus
	

    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    void set_x(int x) {
        this->x = x;
    }
    void set_y(int y) {
        this->y = y;
    }
    virtual void special_action();
};
#endif