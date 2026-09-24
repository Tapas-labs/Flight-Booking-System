#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
#include <string.h>
using namespace std;

class Booking {
    int id,passengerId,flightId,seat;
    char passenger[50],flight[20],status[20],pnr[20];
    double amount;
public:
    Booking();
    Booking(int i,int pi,int fi,int s,const char pa[],const char fl[],double a,const char p[]);
    void cancel();
    void display();
    int getId();
    int getPassengerId();
    int getFlightId();
    int getSeat();
    double getAmount();
    char* getPNR();
    char* getStatus();
    char* getPassengerName();
    char* getFlightNumber();
};
#endif
