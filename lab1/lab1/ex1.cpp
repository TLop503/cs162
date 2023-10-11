#include <iostream>

using namespace std; 

// let x = list to sort, n = length of list(?)
void function (int x[], int n) {
    // i = sentry, t = middleman for swapping, j = n, s = bool that checks completion
    int i, t, j = n, s = 1;
    //while list isn't sorted
    while (s) {
        //assume list will be sorted
        s = 0;
        //fro remaining unsorted items in list
        for (i = 1; i < j; i++) {
            //look at pair. if left is larger swap positions
            if (x[i] < x[i - 1]) {
                t = x[i];
                x[i] = x[i - 1];
                x[i - 1] = t;
                //can't assume list is sorted since we had to make change
                s = 1;
            }
        }
        //largest number is on last index, so we don't need to check it
        j--;
    }
}
 
int main () {
    int x[] = {15, 56, 12, -21, 1, 659, 3, 83, 51, 3, 135, 0};
    //n = length of x[]
    int n = sizeof(x) / sizeof(x[0]);
    int i;
    //print x
    for (i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
    
    //sort
    function(x, n);
    
    //print x again
    for (i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
    
    return 0;
}