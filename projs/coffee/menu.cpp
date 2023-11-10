/*********************************************************************
** Program Filename: menu.cpp
** Author: Troy Lopez
** Date: 11/10/23
** Description: menu class implementation, stored in shop class
*********************************************************************/

#include "menu.h"

#include <iostream>
#include <fstream>

using namespace std;

/**************************************************
 * Name: Menu()
 * Description: default constructor
 * Parameters: n/a
 * Pre-conditions: object created
 * Post-conditions: values populated to 0/nullptr
 ***********************************************/
Menu::Menu(){
	num_coffee = 0;
	coffee_arr = nullptr;
}


/**************************************************
 * Name: search_coffee_by_name(string name)
 * Description: for each coffee if name matches query print coffee
 * Parameters: string name of coffee
 * Pre-conditions: coffee array populated
 * Post-conditions: will print coffee if found
 ***********************************************/
void Menu::search_coffee_by_name(string name) {
	//search coffee with a specific name
	//return the coffee if found
	//Your code goes here:
	bool found = 0;

	for (int i = 0; i < num_coffee; i++) {
		if (coffee_arr[i].get_name() == name) {
			coffee_arr[i].print_coffee();
			found = 1;
		}
	}

	if (!found) {
		cout << "Sorry, we do not have any products with that name right now" << endl;
	}
}


/**************************************************
 * Name: search_coffee_by_price(float budget)
 * Description: for each coffee if price is less than budget print coffee
 * Parameters: float budget
 * Pre-conditions: coffee array populated
 * Post-conditions: will print coffee if found, using size paramater to specify
 ***********************************************/
void Menu::search_coffee_by_price(float budget){
	bool found = 0;
	for (int i = 0; i < num_coffee; i++) {
		cout << endl;
		if (coffee_arr[i].get_large_cost() <= budget) {
			coffee_arr[i].print_coffee();
			found = true;
		}
		else if (coffee_arr[i].get_medium_cost() <= budget) {
			coffee_arr[i].print_coffee('m');
			found = true;
		}
		else if (coffee_arr[i].get_small_cost() <= budget) {
			coffee_arr[i].print_coffee('s');
			found = true;
		}
		cout << endl;
	}
	if (!found) {
		cout << "Sorry, we do not have any drinks for that price" << endl;
	}
}


/**************************************************
 * Name: add_to_menu(Coffee& coffee_to_add)
 * Description: add a coffee object to the Menu
 * Parameters: Coffee& coffee_to_add
 * Pre-conditions: coffee array populated, paramter is a valid coffee object
 * Post-conditions: coffee array will be updated
 ***********************************************/
void Menu::add_to_menu(Coffee& coffee_to_add){
	//upadte menu source file
	ofstream writer;

	writer.open("menu.txt");
	//increment coffee count
	writer << (num_coffee + 1);

	for (int i = 0; i < num_coffee; i++) {
		writer << endl;
		writer << coffee_arr[i].get_name() << " ";
		writer << coffee_arr[i].get_small_cost() << " ";
		writer << coffee_arr[i].get_medium_cost() << " ";
		writer << coffee_arr[i].get_large_cost() << " ";
	}
	writer << endl;
	writer << coffee_to_add.get_name() << " ";
	writer << coffee_to_add.get_small_cost() << " ";
	writer << coffee_to_add.get_medium_cost() << " ";
	writer << coffee_to_add.get_large_cost() << " ";
	writer.close();

	//nuke and pave
	delete[] coffee_arr;
	init("menu.txt");
}


/**************************************************
 * Name: remove_from_menu(int index_of_coffee_on_menu)
 * Description: rebuild menu with every coffee except the one you want to delete
 * Parameters: int index_of_coffee_on_menu - used to get coffee to skip
 * Pre-conditions: coffee array populated, index is valid
 * Post-conditions: coffee array will be updated
 ***********************************************/
void Menu::remove_from_menu(int index_of_coffee_on_menu){
	//remove a coffee object from the Menu
	//Your code goes here:
	ifstream reader;
	reader.open("menu.txt");
	ofstream writer;
	writer.open("tmp.txt");

	//middleman for transferring things
	string liminal;
	getline(reader, liminal); //skip header
	writer << (num_coffee - 1) << endl;

	for (int i = 1; i <= num_coffee; i++) {
		getline(reader, liminal);
		if (i != index_of_coffee_on_menu) {
			writer << liminal << endl;
		}
	}

	remove("menu.txt");
	rename("tmp.txt", "menu.txt");

	delete[] coffee_arr;
	init("menu.txt");
}


/**************************************************
 * Name: init(string input_file)
 * Description: read from file to populate coffee array
 * Parameters: string input_file - menu.txt usually
 * Pre-conditions: input_file is valid
 * Post-conditions: coffee array will be populated
 ***********************************************/
void Menu::init(string input_file){
	ifstream reader;
	reader.open(input_file);

	reader >> num_coffee;
	coffee_arr = new Coffee[num_coffee];
	for (int i = 0; i < num_coffee; i++) {
		string name;
		float price;
		reader >> name;
		coffee_arr[i].set_name(name);

		reader >> price;
		coffee_arr[i].set_small_cost(price);
		reader >> price;
		coffee_arr[i].set_medium_cost(price);
		reader >> price;
		coffee_arr[i].set_large_cost(price);
	}
	///////////////////////////////////////////////
	// cout << "BEGIN DEBUG MESSAGE:" << endl;
	// cout << num_coffee << endl;
	// for (int i = 0; i < num_coffee; i++) {
	// 	cout << coffee_arr[i].get_name() << endl;
	// 	cout << coffee_arr[i].get_small_cost() << endl;
	// 	cout << coffee_arr[i].get_medium_cost() << endl;
	// 	cout << coffee_arr[i].get_large_cost() << endl;
	// }
	// cout << "END DEBUG" << endl;
}


/**************************************************
 * Name: getters
 * Description: access private members
 * Parameters: index for arrays
 * Pre-conditions: everything is non-garbage
 * Post-conditions: returns value
 ***********************************************/
int Menu::get_num_coffee() const {
	return num_coffee;
}
Coffee Menu::get_coffee(int index) const {
	return coffee_arr[index];
}


/////////////////////////////////////////////////////
//big 3
/////////////////////////////////////////////////////

/**************************************************
 * Name: ~Menu()
 * Description: destructor
 * Parameters: n/a
 * Pre-conditions: menu object exists
 * Post-conditions: menu object is destroyed
 ***********************************************/
Menu::~Menu() {
	if (coffee_arr != nullptr) {
		delete[] coffee_arr;
	}
	coffee_arr = nullptr;
	cout << "Menu Destructed" << endl;
}


/**************************************************
 * Name: operator=(const Menu& m)
 * Description: assignment operator
 * Parameters: const Menu& m - menu object to copy
 * Pre-conditions: menu object exists
 * Post-conditions: menu object is assigned
 ***********************************************/
void Menu::operator=(const Menu& m) {
    if (this != &m) { // Check for self-assignment
        num_coffee = m.num_coffee;

        delete[] coffee_arr;
        coffee_arr = nullptr;

        coffee_arr = new Coffee[num_coffee];

        for (int i = 0; i < num_coffee; i++) {
            coffee_arr[i] = m.coffee_arr[i];
        }
    }
}


/**************************************************
 * Name: Menu(const Menu& m)
 * Description: copy constructor
 * Parameters: const Menu& m - menu object to copy
 * Pre-conditions: menu object exists
 * Post-conditions: menu object is copied
 ***********************************************/
Menu::Menu(const Menu& m) {
	num_coffee = m.num_coffee;

	coffee_arr = new Coffee[num_coffee];

	for (int i = 0; i < num_coffee; i++) {
		coffee_arr[i] = m.coffee_arr[i];
	}
}