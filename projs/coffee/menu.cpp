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


//GETTERS
int Menu::get_num_coffee() const {
	return num_coffee;
}


Coffee Menu::get_coffee(int index) const {
	return coffee_arr[index];
}
