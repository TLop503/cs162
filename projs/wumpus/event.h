#ifndef EVENT_H
#define EVENT_H 

using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event
{

protected:
	int x;
    int y;
    char symbol = '?';

public:
    Event();
    Event(int x, int y);
    
    virtual void assert_type();
	char get_symbol() const;
	
};
#endif