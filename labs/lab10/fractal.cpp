#include <iostream>

using namespace std;



string out_white(int white) {
    string out = "";
    for (int i = 0; i < white; i++) {
        out.append(" ");
    }
    return out;
}

void pattern(int stars, int white) {

    if (stars < 1) {
        return;
    }
    // if (stars == 2) {

    //     cout << out_white(white) << "*" << endl
    //     << out_white(white) << "* *" << endl
    //     << out_white(white) << "  *" << endl;
    // }
    else {
        pattern(stars / 2, white);
        cout << out_white(white);
        for (int i = 0; i < stars; i++) {
            cout << "* ";
        }
        cout << endl;
        pattern(stars / 2, white += stars);
    }

}


int main() {
    pattern(2, 0);
    cout << "----------" << endl;
    pattern(4,0);
    cout << "----------" << endl;
    pattern(8,20);
    cout << "----------" << endl;
    pattern(16,0);
}