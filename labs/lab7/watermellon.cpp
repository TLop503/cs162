#include <iostream>

#include "watermellon.h"

using namespace std;

Watermellon::Watermellon() {
    seeds = false;
    Watermellon::set_price();
}

Watermellon::Watermellon(bool seeds, string color, double price) {
    this->seeds = seeds;
    this->color = color;
    this->unit_price = price;
    Watermellon::set_price();
}

void Watermellon::set_price() {
    if (!seeds) {
        unit_price = unit_price * 1.2;
    }
}

void Watermellon::get_name() const {
    cout << "Watermellon" << endl;
}