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

    ///////////////////////
    string quit;
    string input;
    do {
        do {
            cout << "Options:\n 1. Search by Name \n 2. Display Honor Roll \n 3. Sort ID numbers" << endl;
            cin >> input;
        } while (!(input == "1" || input == "2" || input == "3"));
        if (input == "1") {
            search_by_ln(db, size);
        }
        if (input == "2") {
            honor(db, size);
        }
        if (input == "3") {
            exc(db, size);
        }
        do {
            cout << "Want to quit? y/n: ";
            cin >> quit;
        } while (!(quit == "y" || quit == "n"));
    } while (quit != "y");

    delete_student_info(db);
}