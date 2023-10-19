#include <iostream>

using namespace std;

int* create_array1(int size) {
    int* out = new int[size];

    return out;
}

void create_array2(int *& array, int size) {
    array = new int[size];
}

void create_array3(int ** array, int size) {
    *array = new int[size];
}

int main () {

    int in1;
    cout << "enter size for arrays" << endl;
    cin >> in1;

    int* arr1 = create_array1(in1);

    cout << arr1 << endl;

    int* arr2;
    create_array2(arr2, in1);

    cout << arr2 << endl;

    int** arr3;
    int* arr3a;
    arr3 = &arr3a;
    create_array3(arr3, in1);

    cout << arr3 << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3a;
    return 0;
}