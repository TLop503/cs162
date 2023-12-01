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

      vector(vector& target) {
         this->v = NULL;
         if (this->v != NULL) {
            delete [] this->v;
         }
         this->s = target.size();
         this->v = new T[this->s];

 
         //uncomment once [] is implemented
         for (int i = 0; i < target.size(); i++)
            this->v[i] = target[i];
      }

      vector& operator=(vector<T> &target){
         this->s = target.size();
         if (this->v != NULL) {
            delete [] this->v;
         }
         this->v = NULL;
         this->v = new T[this->s];
         //uncomment once [] is implemented
         for (int i = 0; i < target.size(); i++)
            this->v[i] = target[i];

         return *this;
      }   

      //destructor	  
      ~vector(){
         std::cout << "destructor called " << this->v << std::endl;
         if (this->v != NULL) {
            delete [] this->v;
            this->v = NULL;
         }
      }

      T operator[](int i) {
         if (v != NULL && i < this->s) {
            return v[i];
         }
         else {
            std::cout << "Error: index out of bounds" << std::endl;
            //exit(1);

         }
      }

      //size function	  
      int size() {
	     return this->s;
      }

      //push_back: add an element to the end	  
      void push_back(T ele) {
         T *temp;
         //allocate new memory for larger size
         temp = new T[++this->s];
         //copy old values over to temp
         if (this->v != NULL) {
            for(int i = 0; i < this->s-1; i++)
                  temp[i] = this->v[i];
            
            //delete old
            delete [] this->v;
         }

         //set pointer to new memory
         this->v = temp;
         //add new element
         this->v[s-1] = ele;
      }

      void insert(int index, T ele) {
         if (index >= this->s + 1) {
            std::cout << "Index OOB" << std::endl;
            //exit(1);
         }
         T *temp;
         temp = new T[++this->s];

         if (this->v != NULL) {
            for (int i = 0; i < index; i++) {
               temp[i] = this-> v[i];
            }
            temp[index] = ele;
            for (int i = ++index; i < this->s; i++) {
               temp[i] = this->v[i-1];
            }

            delete[] this->v;
         }
         this->v = temp;
      }

};
