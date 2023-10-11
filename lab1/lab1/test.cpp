//Part one of lab 1 is done

#include <iostream>
#include <string>

using namespace std;

void foo(int x);

int main() {
  string name = "Troy Lopez";
  cout << "My name is: " << name << endl;
  foo(2);
  foo(4);
  foo(2 + 4);
  foo(2 - 4);
  foo(2 * 4);
  foo(2 / 4);
}


void foo(int x) {
  cout << "The function foo was passed the number: " << x << endl;
}
