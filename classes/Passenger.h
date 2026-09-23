#ifndef PASSENGER_H
#define PASSENGER_H

#include "User.h"

/*
    Passenger class
    ---------------
    Inherits common information from User and adds passenger-specific data.
*/
class Passenger : public User
{
private:
    string passportNo;
    int baggageAllowance;

public:
    Passenger();

    Passenger(int id, string name, string email,
              string password, string phone,
              string passportNo, int baggageAllowance);

    void displayProfile() override;

    // These methods are kept simple; main.cpp coordinates the actual modules.
    void searchFlight();
    void bookTicket();
    void cancelTicket();
    void viewBookingHistory();

    string getPassportNo() const;
    int getBaggageAllowance() const;
};

#endif
