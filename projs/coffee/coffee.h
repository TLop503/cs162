#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;

  public:
    //need to include accessor functions and mutator functions for private member when appropriate
    //need to include constructors and destructors where appropriate
    //need to use 'const' when appropriate

    /**************************************************
     * Name: Coffee()
     * Description: default constructor
     * Parameters: none
     * Pre-conditions: object created
     * Post-conditions: values will be set to 0/""
     ***********************************************/
    Coffee(); //Coffee constructor


    /**************************************************
     * Name: Coffee(string name, float sm, float me, float lg)
     * Description: constructor
     * Parameters: string name of coffee, prices: float sm, float me, float lg
     * Pre-conditions: object created
     * Post-conditions: values will be set to params
     ***********************************************/
    Coffee(string name, float sm, float me, float lg); //alt con


   /**************************************************
   * Name: Setters
   * Description: mutate private members
   * Parameters: new value
   * Pre-conditions:
   * Post-conditions: value will be updated
   ***********************************************/
    void set_name (const string);
    void set_small_cost(const float);
    void set_medium_cost(const float);
    void set_large_cost(const float);


    /**************************************************
     * Name: Getters
     * Description: access private members
     * Parameters: none
     * Pre-conditions:
     * Post-conditions: value will be returned
     ***********************************************/
    string get_name() const;
    float get_small_cost () const;
    float get_medium_cost () const;
    float get_large_cost () const;


    /**************************************************
     * Name: print_coffee()
     * Description: print coffee object
     * Parameters: none
     * Pre-conditions:
     * Post-conditions: value will be returned
     ***********************************************/
    void print_coffee() const; //print the coffee object


    /**************************************************
     * Name: print_coffee(char size)
     * Description: print coffee object
     * Parameters: char size
     * Pre-conditions:
     * Post-conditions: value will be returned
     ***********************************************/
    void print_coffee(char size) const;
};

#endif