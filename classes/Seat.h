#ifndef SEAT_H
#define SEAT_H
#include <iostream>
using namespace std;

class Seat {
    int number,booked;
public:
    Seat();
    void setNumber(int n);
    bool book();
    void cancel();
    bool isBooked();
    void display();
};
#endif
