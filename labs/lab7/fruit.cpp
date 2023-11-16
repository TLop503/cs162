#include <iostream>

#include "fruit.h"

using namespace std;

string Fruit::get_name() const {
    return name;
}

string Fruit::get_color() const {
    return color;
}

double Fruit::get_price() const {
    return unit_price;
}

void Fruit::set_color(string color) {
    this->color = color;
}

void Fruit::set_price(double price) {
    this->unit_price = price;
}

Fruit::Fruit() {
    this->color = "Default Color";
    this->unit_price = 0;
}

Fruit::Fruit(string color, double price) {
    this->color = color;
    this->unit_price = price;
}