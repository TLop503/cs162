#include <iostream>

using namespace std;

int main(){
    //comments exist
    cout << "Hello World" <<endl;

    int x;

    cout << x << endl; //undef behavior, will be fucked up

    x = 10;

    bool allGood = 1;
    char firstLetter = 'a';

    return 0;
}