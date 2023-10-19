#include <iostream>
#include "multdiv.h"

using namespace std;

int main()
{
	string in = "no";
	do {
		//Your code here:
		int row, col;
		
		cout << "row, column" << endl;
		cin >> row;
		cin >> col;

		multdiv_entry** table = create_table(row, col);
		print_table(table, row, col);
		cout << "again?" << endl;
		cin >> in;
		delete_table(table, row);
	}
	while (in == "y");


	return 0;
}