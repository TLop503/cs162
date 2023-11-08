#include "shop.h"

#include <algorithm>
#include <fstream>

using namespace std;

//function defintions from shop.h goes here

Shop::Shop() {
	load_data();
	revenue = 0; //set this up now so += will work later
}

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

void Shop::place_order() {
	//handle "Place order" option
	//Your code goes here: 
	cout << "Shop::place_order() not implemented..." << endl;

	return;
}

Shop Shop::clone_shop() {
	//handle "Clone a shop" option
	//note: the purpose of this option is to test
	//your big three implementation
	Shop cloned_shop;

	cloned_shop = *this; // test AOO        

    Shop cloned_shop2 = *this; // test CC 

    cout << "Shop cloned successfully!" << endl; 

    return cloned_shop;
}

/////////////////////////////////////////////////////
//big 3

Shop::~Shop() {
	order_arr = nullptr;
    if (num_orders != 0) {
		delete[] order_arr;
	}
	cout << "Shop Destructed" << endl;

}