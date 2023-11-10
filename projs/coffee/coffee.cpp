#include "coffee.h"

#include <iostream>

using namespace std;

/**************************************************
 * Name: Coffee()
 * Description: default constructor
 * Parameters: none
 * Pre-conditions: object created
 * Post-conditions: values will be set to 0/""
 ***********************************************/
Coffee::Coffee() {
    name = "";
    small_cost = 0;
    medium_cost = 0;
    large_cost = 0;

}


/**************************************************
 * Name: Coffee(string name, float sm, float me, float lg)
 * Description: constructor
 * Parameters: string name of coffee, prices: float sm, float me, float lg
 * Pre-conditions: object created
 * Post-conditions: values will be set to params
 ***********************************************/
Coffee::Coffee(string name, float sm, float me, float lg) {
    this->name = name;
    small_cost = sm;
    medium_cost = me;
    large_cost = lg;
    cout << "Coffee " << this->name << " created" << endl;
}


/**************************************************
 * Name: Setters
 * Description: mutate private members
 * Parameters: new value
 * Pre-conditions: 
 * Post-conditions: value will be updated
 ***********************************************/
void Coffee::set_name (const string name){
    this->name = name;
}
void Coffee::set_small_cost(const float cost){
    small_cost = cost;
}
void Coffee::set_medium_cost(const float cost){
    medium_cost = cost;
}
void Coffee::set_large_cost(const float cost){
    large_cost = cost;
}


/**************************************************
 * Name: Getters
 * Description: access private members
 * Parameters: none
 * Pre-conditions: 
 * Post-conditions: value will be returned
 ***********************************************/
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


/**************************************************
 * Name: print_coffee()
 * Description: print coffee object
 * Parameters: none
 * Pre-conditions: 
 * Post-conditions: value will be returned
 ***********************************************/
void Coffee::print_coffee() const{
    cout << "Coffee name: " << name << endl;
    cout << "Small Cost: $" << small_cost << endl;
    cout << "Medium Cost: $" << medium_cost << endl;
    cout << "Large Cost: $" << large_cost << endl;
} //print the coffee object


/**************************************************
 * Name: print_coffee(char size)
 * Description: print coffee object
 * Parameters: char size
 * Pre-conditions: 
 * Post-conditions: value will be returned
 ***********************************************/
void Coffee::print_coffee(char size) const{
    cout << "Coffee name: " << name << endl;
    cout << "Small Cost: $" << small_cost << endl;
    //if size is medium print medium
    if  (size == 'm') {
        cout << "Medium Cost: $" << medium_cost << endl;
    }
} //print the coffee object