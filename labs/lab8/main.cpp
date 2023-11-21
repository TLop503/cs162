#include <iostream>

#include "fruit.h"
#include "apple.h"
#include "watermellon.h"
#include "granny.h"

using namespace std;

void print_fruit_info(Fruit& f) {
    f.get_name();
}


int main(){
    //Fruit f1 = Fruit();
    //Fruit f2 = Fruit("Red", 1.99);
    Apple a1 = Apple();
    Apple a2 = Apple(1.5, true, "Red", 1.99);
    Watermellon w1 = Watermellon();
    Watermellon w2 = Watermellon(false, "Green", 1.99);


    print_fruit_info(a1);
    print_fruit_info(w1);
}