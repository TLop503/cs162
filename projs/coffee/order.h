#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
	//need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate
	
	//print to cout
	void spill_coffee() const;

	//getters
	int get_id() const;
	string get_name() const;
	char get_size() const;
	int get_quantity() const;
};
#endif