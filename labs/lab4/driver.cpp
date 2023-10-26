#include <iostream>
#include <fstream>
#include "student_db.h"

using namespace std;

int main(){
    ifstream reader;
    string file;
    int size;

    cout << "File: ";
    cin >> file;
    reader.open(file);
    //check open
    if (!(reader.is_open())) {
        cout << "Invalid Filename, quitting" << endl;
        return 0;
    }

    //find size of file
    reader >> size;

    Student* db = create_student_db(size);
    populate_student_db_info(db, size, reader);

    search_by_ln(db, size);
    honor(db, size);
}