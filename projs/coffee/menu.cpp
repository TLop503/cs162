#include "menu.h"

#include <iostream>
#include <fstream>

using namespace std;

//function defintions from menu.h goes here


Coffee Menu::search_coffee_by_name(string name) {
	Coffee found; 
	//search coffee with a specific name 
	//return the coffee if found 
	//Your code goes here: 

	return found;
}


Menu Menu::search_coffee_by_price(float budget){
	Menu temp;
	//search coffee with a specific budget 
	//return all coffee that is under the budget
	//Hint: Since a Menu object contains an array of coffee
	//      You may return a Menu object that contains all valid coffees
	//Your code goes here: 

	return temp;

}

void Menu::add_to_menu(Coffee& coffee_to_add){
	//add a coffee object into the Menu
	//Your code goes here: 

	return;
} 


void Menu::remove_from_menu(int index_of_coffee_on_menu){
	//remove a coffee object from the Menu
	//Your code goes here: 

	return;
} 

//populates menu object with data from input file
void Menu::init(string input_file){
	ifstream reader;
	reader.open(input_file);

	reader >> num_coffee;;
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
