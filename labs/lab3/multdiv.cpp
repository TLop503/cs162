#include <iostream>

using namespace std;

struct multdiv_entry {
	int mult;
	float div;
};


//function prototypes
multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** tables, int row, int col);
void delete_table(multdiv_entry** tables, int row);

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