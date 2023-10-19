#include <iostream>
#include "multdiv.h"

using namespace std;

//generate table
multdiv_entry** create_table(int row, int col){
	multdiv_entry** out = new multdiv_entry*[row];
	for (int i = 0; i < row; i++) {
		out[i] = new multdiv_entry[col];
	}
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++ /*lol*/) {
			out[r][c].mult = ((r + 1) * (c + 1));
			out[r][c].div = (float(r + 1) / float(c + 1));
		}
	}

	return out;
}

//iterate, populate, and print table
void print_table(multdiv_entry** tables, int row, int col) {
	cout << "mult:" << endl;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++ /*lol*/) {
			cout << " " << tables[r][c].mult << " ";
		}
		cout << endl;
	}
	cout << "div:" << endl;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++ /*lol*/) {
			cout << " " << tables[r][c].div << " ";
		}
		cout << endl;
	}
}

void delete_table(multdiv_entry** tables, int row){
	for (int r = 0; r < row; r++) {
		delete[] tables[r];
	}
	delete[] tables;
}

