#include <iostream>

#include "granny.h"

using namespace std;


Granny::Granny() {
    this->set_sweetness();
    Granny::set_price();
}

Granny::Granny(float weight, bool sweetness, string color, double price) {
    this->set_weight(0.0);
    this->set_sweetness();
    this->color = color;
    this->unit_price = price;
    Granny::set_price();
}

void Granny::set_sweetness() {
    Apple::set_sweetness(false);
}

void Granny::get_name() const {
    cout << "Granny Smith Apple" << endl;
}