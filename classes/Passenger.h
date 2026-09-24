#ifndef PASSENGER_H
#define PASSENGER_H
#include "User.h"

class Passenger:public User {
    char passportNo[30];
    int baggageAllowance;
public:
    Passenger();
    Passenger(int id,const char n[],const char e[],const char p[],const char ph[],const char pass[],int bag);
    void displayProfile();
    char* getPassportNo();
    int getBaggageAllowance();
};
#endif
