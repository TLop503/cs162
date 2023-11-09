#include "order.h"

#include <iostream>

using namespace std;

//print to cout
void Order::spill_coffee() const {
    cout << "Order ID: " << id << endl;
    cout << quantity << " " << coffee_size << " " << coffee_name << endl;
}

//getters
int Order::get_id() const {
    return id;
}


string Order::get_name() const {
    return coffee_name;
}


char Order::get_size() const {
    return coffee_size;
}


int Order::get_quantity() const {
    return quantity;
}

Order::Order(int id, string coffee_name, char coffee_size, int quantity) {
    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
    spill_coffee();
}

Order::Order(){
    //default
}


