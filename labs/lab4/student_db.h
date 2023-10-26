#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>

using namespace std;


struct Student {
    int id;
    string first_name;
    string last_name;
    string major;
    float gpa;
};

Student* create_student_db(int);
void populate_student_db_info(Student*, int, ifstream&);
void delete_student_info(Student*&);
void search_by_ln(Student*, int);
void honor(Student*, int);

#endif