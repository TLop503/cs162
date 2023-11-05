#include "menu.h"

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
	ofstream reader;
	reader.open(input_file)

	reader >> m.num_coffee;;
	m.coffee_arr = new Coffee[m.num_coffee];
	for (int i = 0; i < menu_size; i++) {
		reader >> m.coffee_arr[i].name;
		reader >> m.coffee_arr[i].small_cost;
		reader >> m.coffee_arr[i].medium_cost;
		reader >> m.coffee_arr[i].large_cost;
	}
	///////////////////////////////////////////////
	cout << "BEGIN DEBUG MESSAGE:" << endl;
	cout << m.num_coffee << endl;
	for (int i = 0; i < menu_size; i++) {
		cout << m.coffee_arr[i].name << endl;
		cout << m.coffee_arr[i].small_cost << endl;
		cout << m.coffee_arr[i].medium_cost << endl;
		cout << m.coffee_arr[i].large_cost << endl;
	}
	cout << "END DEBUG" << endl;
}
