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

	return out;
}

//iterate and print table
void print_table(multdiv_entry** tables, int row, int col) {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++ /*lol*/) {
			tables[r][c].mult = (r * c);
			tables[r][c].div = (r / c);
		}
	}
}

int main()
{
	//Your code here:
	int row, col;
	
	cout << "row, column" << endl;
	cin >> row;
	cin >> col;

	multdiv_entry** table = create_table(row, col);
	
	
	return 0;
}