#ifndef BAGGAGE_H
#define BAGGAGE_H
#include <iostream>
using namespace std;

class Baggage {
    int weight;
    double charge;
public:
    Baggage();
    Baggage(int w);
    void calculate();
    void display();
    double getCharge();
};
#endif
