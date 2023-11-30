#include <iostream>

#include "apple.h"

using namespace std;

void Apple::set_price(){
    unit_price = weight * unit_price;
}

Apple::Apple(){
    weight = 0;
    sweetness = false;
    Apple::set_price();
}

Apple::Apple(float weight, bool sweetness, string color, double price){
    this->weight = weight;
    this->sweetness = sweetness;
    this->color = color;
    this->unit_price = price;
    Apple::set_price();
}

void Apple::set_sweetness(bool sweet){
    sweetness = sweet;
}

void Apple::set_weight(float weight){
    this->weight = weight;
}

bool Apple::get_sweetness() const {
    return this->sweetness;
}

void Apple::get_name() const {
    cout << "Apple" << endl;
}