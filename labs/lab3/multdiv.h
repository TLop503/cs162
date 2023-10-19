struct multdiv_entry {
	int mult;
	float div;
};


//function prototypes
multdiv_entry** create_table(int row, int col);
void print_table(multdiv_entry** tables, int row, int col);
void delete_table(multdiv_entry** tables, int row);