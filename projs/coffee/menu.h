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
    /**************************************************
   * Name: search_coffee_by_name(string name)
   * Description: for each coffee if name matches query print coffee
   * Parameters: string name of coffee
   * Pre-conditions: coffee array populated
   * Post-conditions: will print coffee if found
   ***********************************************/
    void search_coffee_by_name(string name); 


    /**************************************************
   * Name: search_coffee_by_price(float budget)
   * Description: for each coffee if price is less than budget print coffee
   * Parameters: float budget
   * Pre-conditions: coffee array populated
   * Post-conditions: will print coffee if found, using size paramater to specify
   * ***********************************************/
    void search_coffee_by_price(float budget); 


    /**************************************************
   * Name: add_to_menu(Coffee& coffee_to_add)
   * Description: add a coffee object to the Menu
   * Parameters: Coffee& coffee_to_add
   * Pre-conditions: coffee array populated, paramter is a valid coffee object
   * Post-conditions: coffee array will be updated
   ***********************************************/
    void add_to_menu(Coffee& coffee_to_add); //add a coffee object into the Menu


    /**************************************************
   * Name: remove_from_menu(int index_of_coffee_on_menu)
   * Description: rebuild menu with every coffee except the one you want to delete
   * Parameters: int index_of_coffee_on_menu - used to get coffee to skip
   * Pre-conditions: coffee array populated, index is valid
   * Post-conditions: coffee array will be updated
   ***********************************************/
    void remove_from_menu(int index_of_coffee_on_menu); //remove a coffee object from the Menu


    /**************************************************
   * Name: init(string input_file)
   * Description: read from file to populate coffee array
   * Parameters: string input_file - menu.txt usually
   * Pre-conditions: input_file is valid
   * Post-conditions: coffee array will be populated
   ***********************************************/
    void init(string input_file);


    /**************************************************
   * Name: getters
   * Description: access private members
   * Parameters: index for arrays
   * Pre-conditions: everything is non-garbage
   * Post-conditions: returns value
   ***********************************************/
    int get_num_coffee() const;
    Coffee get_coffee(int index) const;

    /**************************************************
     * Name: Menu()
     * Description: default constructor
     * Parameters: n/a
     * Pre-conditions: object created
     * Post-conditions: values populated to 0/nullptr
     ***********************************************/
    Menu();

    //big 3

    /**************************************************
     * Name: ~Menu()
     * Description: destructor
     * Parameters: n/a
     * Pre-conditions: object created
     * Post-conditions: values populated to 0/nullptr
     ***********************************************/
    ~Menu();


    /**************************************************
   * Name: operator=(const Menu& m)
   * Description: assignment operator
   * Parameters: const Menu& m - menu object to copy
   * Pre-conditions: menu object exists
   * Post-conditions: menu object is assigned
   ***********************************************/
    void operator=(const Menu& m);


    /**************************************************
   * Name: Menu(const Menu& m)
   * Description: copy constructor
   * Parameters: const Menu& m - menu object to copy
   * Pre-conditions: menu object exists
   * Post-conditions: menu object is copied
   ***********************************************/
    Menu(const Menu& m);
};

#endif