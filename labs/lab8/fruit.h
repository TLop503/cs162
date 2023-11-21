#ifndef FRUIT_H
#define FRUIT_H

#include <iostream>

using namespace std;

class Fruit {
    protected:
        const string name = "Default Fruit";
        string color;
        double unit_price;
    private:
    public:
        Fruit();
        Fruit(string color, double price);

        virtual string get_name() const;
        string get_color() const;
        double get_price() const;

        void set_color(string color);
        void set_price(double price);
};

#endif