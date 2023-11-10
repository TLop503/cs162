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

    /**************************************************
    * Name: Shop()
    * Description: default constructor
    * Parameters: n/a
    * Pre-conditions: Shop object is created
    * Post-conditions: will call load_data()
    ***********************************************/
    Shop();

    /**************************************************
    * Name: load_data()
    * Description: reads from files to correctly populate coffee, menu, etc.
    * Parameters: n/a
    * Pre-conditions: Shop object is created
    * Post-conditions: will populate internal objects with data from text files
    ***********************************************/
    void load_data(); //reads from files to correctly populate coffee, menu, etc.


    /**************************************************
    * Name: view_shop_detail()
    * Description: cout details about shop
    * Parameters: none
    * Pre-conditions: private vars aren't garbage
    * Post-conditions: n/a
    ***********************************************/
    void view_shop_detail();


   /**************************************************
   * Name: add_to_menu()
   * Description: choose item to add to menu
   * Parameters: n/a
   * Pre-conditions: menu object is initialized
   * Post-conditions: calls menu subproccess to edit menu.txt
   ***********************************************/
    void add_to_menu();


   /**************************************************
   * Name: remove_from_menu()
   * Description: search and destroy
   * Parameters: n/a
   * Pre-conditions: menu has items to remove
   * Post-conditions: calls subprccess to edit menu.txt
   ***********************************************/
    void remove_from_menu();


    /**************************************************
   * Name: search_by_name()
   * Description: calls menu search function
   * Parameters: n/a
   * Pre-conditions: menu is correctly populated
   * Post-conditions: calls menu search function
   ***********************************************/
    void search_by_name();


    /**************************************************
   * Name: search_by_price()
   * Description: calls menu search function with price param
   * Parameters: n/a
   * Pre-conditions: menu is correctly populated
   * Post-conditions: calls menu search function with price param
   ***********************************************/
    void search_by_price();


    /**************************************************
   * Name: place_order()
   * Description: calls enter_order() with user input
   * Parameters: n/a
   * Pre-conditions: menu is correctly populated
   * Post-conditions: calls enter_order() with user input
   ***********************************************/
    void place_order();


   /**************************************************
   * Name: clone_shop()
   * Description: clones shop object with cc, aoo
   * Parameters: n/a
   * Pre-conditions: shop object is correctly populated
   * Post-conditions: returns cloned shop object
   ***********************************************/
    Shop clone_shop();


    /**************************************************
   * Name: enter_order()
   * Description: creates and resizes order arr with input from above
   * Parameters: int choice -- name of drink, int quan -- how many drinks, string size -- size of drink
   * Pre-conditions: user input has been vetted
   * Post-conditions: calls write_orders()
   ***********************************************/
    void enter_order(int choice, int quan, string size);


    /**************************************************
   * Name: write_orders()
   * Description: writes orders to text file
   * Parameters: n/a
   * Pre-conditions: order_arr is correctly populated
   * Post-conditions: writes orders to text file, overwriting old values
   ***********************************************/
    void write_orders();

   /**************************************************
   * Name: check()
   * Description: debug function to check memory address of order_arr
   * for use in verifying cloning
   * Parameters: n/a
   * Pre-conditions: Shop object is created
   * Post-conditions: will print memory address of order_arr
   ***********************************************/
    void check();

    //big 3

    /**************************************************
   * Name: ~Shop()
   * Description: destructor
   * Parameters: n/a
   * Pre-conditions: shop object exists
   * Post-conditions: deletes order_arr
   ***********************************************/
    ~Shop();


    /**************************************************
     * Name: operator=()
     * Description: assignment operator
     * Parameters: const Shop& s -- shop object to copy
     * Pre-conditions: shop object is correctly populated
     * Post-conditions: deletes order_arr and copies values from s
     ***********************************************/
    void operator=(const Shop& s);


    /**************************************************
   * Name: Shop()
   * Description: copy constructor
   * Parameters: const Shop& s -- shop object to copy
   * Pre-conditions: shop object is correctly populated
   * Post-conditions: copies values from s
   ***********************************************/
    Shop(const Shop& s);

};

#endif
