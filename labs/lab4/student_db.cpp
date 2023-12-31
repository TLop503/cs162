#include <iostream>
#include "student_db.h"

using namespace std;

Student* create_student_db(int size){
    Student* out = new Student[size];
    return out;
}

void populate_student_db_info(Student* students, int size, ifstream& reader) {
    for (int i = 0; i < size; i++ ) {
        reader >> students[i].id;
        reader >> students[i].first_name;
        reader >> students[i].last_name;
        reader >> students[i].major;
        reader >> students[i].gpa;
    }
}

void delete_student_info(Student*& students) {
    delete[] students;
}

void search_by_ln(Student* students, int size) {
    ofstream writer;
    writer.open("output.txt", ios::app);

    string name;

    cout << "Enter last name: ";
    cin >> name;

    writer << "NAME QUERY RESULTS: " << endl;

    for (int i = 0; i < size; i++) {
        if (name == students[i].last_name) {
            Student s = students[i];
            writer << "ID: " << s.id << "\nFirst Name: " << s.first_name << "\nLast Name: " << s.last_name << "\nMajor: " << s.major << "\nGPA: " << s.gpa << endl << endl;
        }
    }
}

void honor(Student* students, int size) {
    ofstream writer;
    writer.open("output.txt", ios::app);
    writer << "HONOR ROLL: " << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].gpa >= 3.5) {
            Student s = students[i];
            writer << "ID: " << s.id << "\nFirst Name: " << s.first_name << "\nLast Name: " << s.last_name << "\nMajor: " << s.major << "\nGPA: " << s.gpa << endl << endl;
        }
    }
}

//code stolen from w3schools
void exc(Student* st, int size) {
    int i, j;
    int n = size;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (st[j].id > st[j + 1].id) {
                swap(st[j], st[j + 1]);
                swapped = true;
            }
        }
 
    }
    ofstream writer;
    writer.open("output.txt", ios::app);
    writer << "SORTED IDS: " << endl;
    for (int l = 0; l < size; l++) {
        writer << st[l].id << endl;
    }
}