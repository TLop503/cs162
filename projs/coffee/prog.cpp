#include <iostream>
#include "display.h"

using namespace std;

int main()
{
	//your main function lives here
	cout << endl << "Welcome to Java++" << endl;
	int choice = -1;
	Shop s;

	s.load_data();

	while (choice != QUIT){
		choice = get_choice();
	 	perform_action(s, choice);
	}

	cout << "Bye!" << endl;

	return 0;
}
