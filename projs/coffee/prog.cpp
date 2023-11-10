/*********************************************************************
** Program Filename: prog.cpp
** Author: skeleton code, mostly
** Date: 11/10/23
** Description: main access point for program
*********************************************************************/

#include <iostream>
#include "display.h"

using namespace std;

// stock from assignemnt skeleton code
int main()
{
	//your main function lives here
	cout << endl << "Welcome to Java++" << endl;
	int choice = -1;
	Shop s;

	while (choice != QUIT){
		choice = get_choice();
	 	perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
