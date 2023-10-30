#include <iostream>

using namespace std;

class page{
    private:
        string content;
    public:
        //setter to change content value
        void set_content (const string& content) {
            this->content = content;
        }
        //print
        void print() const {
            cout << this->content << endl;
        }
};



int main(){

}