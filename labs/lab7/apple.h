#ifndef APPLE_H
#define APPLE_H

#include <iostream>

#include "fruit.h"

class Apple : public Fruit {
    private:
        float weight;
        bool sweetness; //is_sweet
    public:
        void set_price();
        void set_sweetness(bool sweet);
        void set_weight(float weight);
        
        bool get_sweetness() const;
        void get_name() const;

        Apple();
        Apple(float weight, bool sweetness, string color, double price);
        
};

#endif