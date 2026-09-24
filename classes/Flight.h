#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <string.h>
#include "Seat.h"
using namespace std;

class Flight {
    int id;
    char number[20],airline[40],source[40],destination[40],departure[20],arrival[20];
    double fare;
    Seat seats[20];
public:
    Flight();
    Flight(int i,const char no[],const char air[],const char from[],const char to[],const char dep[],const char arr[],double f);
    void display();
    void showSeats();
    bool matches(const char from[],const char to[]);
    bool bookSeat(int n);
    void cancelSeat(int n);
    bool seatAvailable(int n);
    int getId();
    char* getNumber();
    char* getSource();
    char* getDestination();
    char* getAirline();
    char* getDeparture();
    char* getArrival();
    double getFare();
};
#endif
