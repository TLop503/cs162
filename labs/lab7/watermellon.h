#ifndef WATER_H
#define WATER_H

#include <iostream>

#include "fruit.h"

using namespace std;

class Watermellon : public Fruit {
    private:
        bool seeds; //has seeds
    public:
        Watermellon();
        Watermellon(bool seeds, string color, double price);
        void set_price();
        void get_name() const;
};

#endif