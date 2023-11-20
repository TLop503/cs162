#ifndef GOLD_H
#define GOLD_H 

//Gold Interface
#include "gold.h"
#include "event.h"

#include <iostream>

using namespace std;

//Wumpus Implementation
class Gold : public Event {
    public:
        Gold();

        void assert_type();
    protected:
    private:
};


#endif