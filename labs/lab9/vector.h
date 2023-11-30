#include <stdlib.h>
#include <iostream>

template <class T>
class vector {
   private:
      T *v;  //a dynamic array of elements of type T
      int s; //size
   public:
      //default constructor
      vector(){
	     this->s = 0;
	     this->v = NULL;
      }

      //destructor	  
      ~vector(){
	     delete [] this->v;
	     this->v = NULL;
      }
	
      //size function	  
      int size() {
	     return this->s;
      }

      //push_back: add an element to the end	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++this->s];
	     for(int i = 0; i < this->s-1; i++)
	        temp[i] = this->v[i];

	     if (this->v != NULL)
	     	delete [] this->v;
	     this->v = temp;
	     this->v[s-1] = ele;
      }

};
