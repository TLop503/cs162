/*********************************************************************
** Program Filename: shop.cpp
** Author: Troy Lopez
** Date: 11/10/23
** Description: shop class implementation
**** central nervous system of program, delegates tasks to other classes
*********************************************************************/

#include "shop.h"

#include <algorithm>
#include <fstream>

using namespace std;

/**************************************************
 * Name: Shop()
 * Description: default constructor
 * Parameters: n/a
 * Pre-conditions: Shop object is created
 * Post-conditions: will call load_data()
 ***********************************************/
Shop::Shop() {
	revenue = 0;
	phone = "";
	address = "";
	num_orders = 0;
	order_arr = nullptr;
	load_data();
}


/**************************************************
 * Name: check()
 * Description: debug function to check memory address of order_arr
 * for use in verifying cloning
 * Parameters: n/a
 * Pre-conditions: Shop object is created
 * Post-conditions: will print memory address of order_arr
 ***********************************************/
void Shop::check() {
	cout << &order_arr << endl;
}


/**************************************************
 * Name: load_data()
 * Description: reads from files to correctly populate coffee, menu, etc.
 * Parameters: n/a
 * Pre-conditions: Shop object is created
 * Post-conditions: will populate internal objects with data from text files
 ***********************************************/
void Shop::load_data(){
	//reads from files to correctly populate coffee, menu, etc.
	//Your code goes here:
	cout << "Loading menu data..." << endl;
	m.init("menu.txt");
	cout << "Done" << endl;

	cout << "Loading shop data..." << endl;
	ifstream reader;
	reader.open("shop_info.txt");
	reader >> phone;

	//address is 3 items so we have to append things
	//This will leave a trailing whitespace that I'll clean if required
	string middleman;
	for (int i = 0; i < 3; i++) {
		reader >> middleman;
		address.append(middleman);
		address.append(" ");
	}
	cout << "Done" << endl;

	// cout << "BEGIN DEBUG MESSAGE: " << endl;
	// cout << phone << endl;
	// cout << address << endl;
	// cout << "END DEBUG MESSAGE" << endl;
	return;
}


/**************************************************
 * Name: view_shop_detail()
 * Description: cout details about shop
 * Parameters: none
 * Pre-conditions: private vars aren't garbage
 * Post-conditions: n/a
 ***********************************************/
void Shop::view_shop_detail(){
	//handle "View shop detail" option
	//print shop address, phone number, revenue, menu, and order
	//Your code goes here:

	//if over 15 lines it's because they are almost all couts
	cout << "Phone: " << phone << endl;
	cout << "Address: " << address << endl;
	cout << "Revenue: $" << revenue << endl;
	cout << endl;
	cout << "Orders: " << endl;

	if (num_orders == 0) {
		cout << "No orders yet" << endl;
	}
	for (int i = 0; i < num_orders; i++) {
		order_arr[i].spill_coffee();
	}
	cout << endl;

	cout << "Menu: " << endl;
	for (int i = 0; i < m.get_num_coffee(); i++) {
		m.get_coffee(i).print_coffee();
		cout << endl;
	}


	return;
}


/**************************************************
 * Name: add_to_menu()
 * Description: choose item to add to menu
 * Parameters: n/a
 * Pre-conditions: menu object is initialized
 * Post-conditions: calls menu subproccess to edit menu.txt
 ***********************************************/
void Shop::add_to_menu(){
	//handle "Add coffee to menu" option
	//Hint: call Menu::add_to_menu(Coffee& coffee_to_add);
	//Your code goes here:
	string name;
	string prices_o[3] = {"small", "medium", "large"};
	float prices_i[3];

	cout << "Enter name for a drink: ";
	cin >> name;
	//if user has any spaces swap them for underscores

	//get each price
	cout << "Enter prices:" << endl;
	//super hacky way to minimize lines of code lol
	for (int i = 0; i < 3; i++) {
		cout << prices_o[i] << ": ";
		cin >> prices_i[i];
	}

	Coffee out = Coffee(name, prices_i[0], prices_i[1], prices_i[2]);
	//cast prices to floats
	cout << "test";
	cout << out.get_name();
	m.add_to_menu(out);

	return;
}


/**************************************************
 * Name: remove_from_menu()
 * Description: search and destroy
 * Parameters: n/a
 * Pre-conditions: menu has items to remove
 * Post-conditions: calls subprccess to edit menu.txt
 ***********************************************/
void Shop::remove_from_menu(){
	//handle "Remove coffee from menu" option
	//Hint: call Menu::remove_from_menu(int index_of_coffee_on_menu);
	//Your code goes here:
	int choice;

	cout << "Which of our drinks would you like to remove from the menu?" << endl;
	cout << "1 - " << m.get_num_coffee() << endl;

	for (int i = 0; i < m.get_num_coffee(); i++) {
		//print menu with only names
		cout << (i + 1) << ". " << m.get_coffee(i).get_name() << endl;
	}

	do {
		cout << "Enter number in range: ";
		cin >> choice;

		//while negative or too big ask again
	} while (choice < 0 || choice >= (m.get_num_coffee() + 1));

	//choice is 1 larger than array index but will match file line number
	m.remove_from_menu(choice);
	return;
}


/**************************************************
 * Name: search_by_name()
 * Description: calls menu search function
 * Parameters: n/a
 * Pre-conditions: menu is correctly populated
 * Post-conditions: calls menu search function
 ***********************************************/
void Shop::search_by_name(){
	//handle "Search by coffee name" option
	//Hint: call Menu::search_coffee_by_name(string name);
	//Your code goes here:
	string in;

	cout << "Enter a name (1 word) to search for: ";
	cin >> in;

	m.search_coffee_by_name(in);
	return;
}


/**************************************************
 * Name: search_by_price()
 * Description: calls menu search function with price param
 * Parameters: n/a
 * Pre-conditions: menu is correctly populated
 * Post-conditions: calls menu search function with price param
 ***********************************************/
void Shop::search_by_price(){
	//handle "Search by coffee price" option
	//Hint: call Menu::search_coffee_by_price(float budget);
	//Your code goes here:
	float in;

	cout << "Enter the price you'd like to search at or below: ";
	cin >> in;
	m.search_coffee_by_price(in);

	return;
}


/**************************************************
 * Name: place_order()
 * Description: calls enter_order() with user input
 * Parameters: n/a
 * Pre-conditions: menu is correctly populated
 * Post-conditions: calls enter_order() with user input
 ***********************************************/
void Shop::place_order() {
	//handle "Place order" option
	//Your code goes here:
	int choice, quan;
	string size;

	for (int i = 0; i < m.get_num_coffee(); i++ ) {
		cout << i << ": ";
		m.get_coffee(i).print_coffee();
		cout << endl;
	}

	do {
		cout << "Enter number in range: ";
		cin >> choice;
		//while negative or too big ask again
	} while (choice < 0 || choice >= (m.get_num_coffee() + 1));

	do {
	cout << "Enter Size (s, m, l): ";
	cin >> size;
	//while negative or too big ask again
	} while (!(size == "s" || size == "m" || size == "l"));

	do {
		cout << "Enter quanitity: ";
		cin >> quan;	//type checking isn't required
	} while (quan < 1);

	enter_order(choice, quan, size);

	return;
}


/**************************************************
 * Name: enter_order()
 * Description: creates and resizes order arr with input from above
 * Parameters: int choice -- name of drink, int quan -- how many drinks, string size -- size of drink
 * Pre-conditions: user input has been vetted
 * Post-conditions: calls write_orders()
 ***********************************************/
void Shop::enter_order(int choice, int quan, string size) {
	//create new array and clone values
	Order *temp = new Order[num_orders];
	for (int i = 0; i < num_orders; i++) {
		temp[i] = order_arr[i];
	}

	//cleanup
	delete[] order_arr;
	order_arr = new Order[num_orders + 1];

	for (int i = 0; i < num_orders; i++ ) {
		order_arr[i] = temp[i];
	}

	delete[] temp;

	//since num_of_orders is 1 larger than old index count
	// this will fill new order index
	order_arr[num_orders] = Order(num_orders + 1, m.get_coffee(choice).get_name(), size[0], quan);
	num_orders++;

	//slightly over line limit b/c of revenue logic, this could have been an attrocious
	//ternary instead but I split it for readability.
	if (size[0] == 's') {
		revenue += m.get_coffee(choice).get_small_cost() * quan;
	}
	else if (size[0] == 'm') {
		revenue += m.get_coffee(choice).get_medium_cost() * quan;
	}
	else if (size[0] == 'l') {
		revenue += m.get_coffee(choice).get_large_cost() * quan;
	}

	write_orders();
}


/**************************************************
 * Name: write_orders()
 * Description: writes orders to text file
 * Parameters: n/a
 * Pre-conditions: order_arr is correctly populated
 * Post-conditions: writes orders to text file, overwriting old values
 ***********************************************/
void Shop::write_orders() {
	ofstream writer;
	writer.open("orders.txt"); //intentionally overwrite old text

	writer << num_orders << endl;

	for (int i = 0; i < num_orders; i++) {
		writer <<
		order_arr[i].get_id() << ". " <<
		order_arr[i].get_quantity() << " " <<
		order_arr[i].get_size() << " " <<
		order_arr[i].get_name() <<
		endl;
	}

	writer.close();
}


/**************************************************
 * Name: clone_shop()
 * Description: clones shop object with cc, aoo
 * Parameters: n/a
 * Pre-conditions: shop object is correctly populated
 * Post-conditions: returns cloned shop object
 ***********************************************/
Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;
	cout << "AOO..." << endl;
	cloned_shop = *this; // test AOO
	cout << "CC..." << endl;
    Shop cloned_shop2 = *this; // test CC

    cout << "Shop cloned successfully!" << endl;

    return cloned_shop;
}

/////////////////////////////////////////////////////
//big 3
/////////////////////////////////////////////////////

/**************************************************
 * Name: ~Shop()
 * Description: destructor
 * Parameters: n/a
 * Pre-conditions: shop object exists
 * Post-conditions: deletes order_arr
 ***********************************************/
Shop::~Shop() {
	if (order_arr != nullptr) {
		delete[] order_arr;
	}
	order_arr = nullptr;
	cout << "Shop Destructed" << endl;

}


/**************************************************
 * Name: operator=()
 * Description: assignment operator
 * Parameters: const Shop& s -- shop object to copy
 * Pre-conditions: shop object is correctly populated
 * Post-conditions: deletes order_arr and copies values from s
 ***********************************************/
void Shop::operator=(const Shop& s) {
    if (this != &s) {
        m = s.m;
        phone = s.phone;
        address = s.address;
        revenue = s.revenue;

        if (num_orders != s.num_orders) {
            delete[] order_arr; //free up any existing space
            num_orders = s.num_orders; // update num_orders before allocating new memory
            order_arr = new Order[num_orders];
        }

        for (int i = 0; i < num_orders; i++ ) {
            order_arr[i] = s.order_arr[i];
        }
    }
}


/**************************************************
 * Name: Shop()
 * Description: copy constructor
 * Parameters: const Shop& s -- shop object to copy
 * Pre-conditions: shop object is correctly populated
 * Post-conditions: copies values from s
 ***********************************************/
Shop::Shop(const Shop& s) {
	m = s.m;
	phone = s.phone;
	address = s.address;
	revenue = s.revenue;
	num_orders = s.num_orders;

	order_arr = new Order[num_orders];

	for (int i = 0; i < num_orders; i++ ) {
		order_arr[i] = s.order_arr[i];
	}

}