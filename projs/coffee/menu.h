#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    //need to use 'const' when appropriate

    // Suggested functions:
    void search_coffee_by_name(string name); 
    void search_coffee_by_price(float budget); 
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu
    void init(string input_file);

    //getters
    int get_num_coffee() const;
    Coffee get_coffee(int index) const;

    //con
    Menu();

    //big 3
    ~Menu();
    void operator=(const Menu& m);
    Menu(const Menu& m);
};

#endif