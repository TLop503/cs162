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
	
	/**************************************************
	 * Name: spill_coffee()
	 * Description: prints out order info
	 * Parameters: n/a
	 * Pre-conditions: order has populated member vars
	 * Post-conditions: will print to cout
	 ***********************************************/
	void spill_coffee() const;

	/**************************************************
	 * Name: getters
	 * Description: accessors for private member vars
	 * Parameters: n/a
	 * Pre-conditions: values exist
	 * Post-conditions: values are returned
	 ***********************************************/
	int get_id() const;
	string get_name() const;
	char get_size() const;
	int get_quantity() const;

	Order();

	/**************************************************
	 * Name: Order(int id, string coffee_name, char coffee_size, int quantity)
	 * Description: constructor
	 * Parameters: int id of order, string coffee_name, char coffee_size, int quantity of coffees
	 * Pre-conditions: n/a
	 * Post-conditions: values are populated
	 * ***********************************************/
	Order(int id, string coffee_name, char coffee_size, int quantity);
};
#endif