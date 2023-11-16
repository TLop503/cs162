#include <iostream>

#include "fruit.h"
#include "apple.h"
#include "watermellon.h"
#include "granny.h"

using namespace std;

int main(){
    Fruit f1 = Fruit();
    Fruit f2 = Fruit("Red", 1.99);
    Apple a1 = Apple();
    Apple a2 = Apple(1.5, true, "Red", 1.99);
    Watermellon w1 = Watermellon();
    Watermellon w2 = Watermellon(false, "Green", 1.99);

    Granny g1 = Granny();

    // cout << f1.get_name() << endl;
    cout << f1.get_color() << endl;
    cout << f1.get_price() << endl;

    // cout << f2.get_name() << endl;
    cout << f2.get_color() << endl;
    cout << f2.get_price() << endl;

    // cout << a1.get_name() << endl;
    cout << a1.get_color() << endl;
    cout << a1.get_price() << endl;

    // cout << a2.get_name() << endl;
    cout << a2.get_color() << endl;
    cout << a2.get_price() << endl;

    // cout << w1.get_name() << endl;
    cout << w1.get_color() << endl;
    cout << w1.get_price() << endl;

    // cout << w2.get_name() << endl;
    cout << w2.get_color() << endl;
    cout << w2.get_price() << endl;
    
    cout << "assert granny smith isn't sweet" << endl;
    // cout << a2.get_name() << endl;
    cout << "Apple:" << endl;
    cout << a2.get_sweetness() << endl;
    // cout << g1.get_name() << endl;
    cout << "Granny:" << endl;
    cout << g1.get_sweetness() << endl;
}