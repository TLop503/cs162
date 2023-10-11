#include <iostream>

using namespace std;


void change_first_el(bool arr[]) {
    cout << arr[0] << endl;
    arr[0] = !arr[0];
    cout << arr[0] << endl;
}

void change_me(int* x) {
    *x = 0;
}

int main() {
    bool my_arr[5] = {0,0,0,0,0};
    change_first_el(my_arr);

    cout << my_arr[0] << endl << "---------" << endl;
    
    //////////////////////////////////////

    int y = 10;
    
    //pointer p points to address of int y
    int* p = &y;

    cout << p << endl;

    //indirection / dereference
    //modifies y via p
    *p = 100;

    cout << y << endl;

    return 0;
}