#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    //default constructor calls load data
    Shop();

    //Suggested functions
    void load_data(); //reads from files to correctly populate coffee, menu, etc.
    void view_shop_detail();
    void add_to_menu();
    void remove_from_menu();
    void search_by_name();
    void search_by_price();
    void place_order();
    Shop clone_shop();
    void enter_order(int choice, int quan, string size);
    void write_orders();
    void check();

    //big 3
    ~Shop();
    void operator=(const Shop& s);
    Shop(const Shop& s);

};

#endif
