/*********************************************************************
** Program Filename: order.cpp
** Author: Troy Lopez
** Date: 11/10/23
** Description: order class implementation, stored in shnp class
*********************************************************************/

#include "order.h"

#include <iostream>

using namespace std;

/**************************************************
 * Name: spill_coffee()
 * Description: prints out order info
 * Parameters: n/a
 * Pre-conditions: order has populated member vars
 * Post-conditions: will print to cout
 ***********************************************/
void Order::spill_coffee() const {
    cout << "Order ID: " << id << endl;
    cout << quantity << " " << coffee_size << " " << coffee_name << endl;
}

/**************************************************
 * Name: getters
 * Description: accessors for private member vars
 * Parameters: n/a
 * Pre-conditions: values exist
 * Post-conditions: values are returned
 ***********************************************/
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

/**************************************************
 * Name: Order(int id, string coffee_name, char coffee_size, int quantity)
 * Description: constructor
 * Parameters: int id of order, string coffee_name, char coffee_size, int quantity of coffees
 * Pre-conditions: n/a
 * Post-conditions: values are populated
 * ***********************************************/
Order::Order(int id, string coffee_name, char coffee_size, int quantity) {
    this->id = id;
    this->coffee_name = coffee_name;
    this->coffee_size = coffee_size;
    this->quantity = quantity;
    spill_coffee(); //for diagnostics
}
Order::Order(){
    //default
}