#include <iostream>

using namespace std;

//num to be checked, sentry, output pbr
void function(int num, int ctr, int &r) {
  int i;
  //for all numbers between 2 and num/2
  for(i = 2;i <= num/2; i++){
    //if i is factor of num increase sentry
    if(num % i==0){
      ctr++;
      break;
    }
  }
  //if sentry never triggered and num is not 1 return true
  if(ctr == 0 && num != 1)
    r = 1;
  
  else
    r = 0;
}
//this won't work on negative numbers

int main(){

  int num, ctr = 0, r = -1;
  cout << "Input a number: ";
  cin >> num;
  
  function(num, ctr, r);
  cout << r << endl;;

  return 0;
}