#include "coffee.h"

#include <iostream>

using namespace std;

//default con, values are 0
Coffee::Coffee() {
    name = "";
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;

}

Coffee::Coffee(string name) {
    this->name = name;
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;
    cout << "Coffee " << this->name << " created" << endl;
}


//Coffee constructor
void Coffee::set_name (const string name){
    this->name = name;
}

//setters
void Coffee::set_small_cost(const float cost){
    small_cost = cost;
}
void Coffee::set_medium_cost(const float cost){
    medium_cost = cost;
}
void Coffee::set_large_cost(const float cost){
    large_cost = cost;
}

//getters
string Coffee::get_name() const{
    return name;
}
float Coffee::get_small_cost () const{
    return small_cost;
}
float Coffee::get_medium_cost () const{
    return medium_cost;
}
float Coffee::get_large_cost () const{
    return large_cost;
}

//print
void Coffee::print_coffee() const{
    cout << "Coffee name: " << name << endl;
    cout << "Small Cost: $" << small_cost << endl;
    cout << "Medium Cost: $" << medium_cost << endl;
    cout << "Large Cost: $" << large_cost << endl;
} //print the coffee object