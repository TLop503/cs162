#ifndef GRANNY_H
#define GRANNY_H

#include <iostream>

#include "apple.h"

using namespace std;

class Granny : public Apple {
    private:
        
    public:
        Granny();
        Granny(float weight, bool sweetness, string color, double price);
        
        void set_sweetness();
        void get_name() const;

};

#endif