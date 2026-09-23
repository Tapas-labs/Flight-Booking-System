#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

/*
    Ticket class
    ------------
    Represents the final ticket generated after successful booking.
*/
class Ticket
{
private:
    string pnr;
    int bookingId;
    string passengerName;
    string flightNumber;
    string route;
    string seatNumber;
    double fare;

public:
    Ticket()
    {
        pnr = "";
        bookingId = 0;
        fare = 0;
    }

    Ticket(int bookingId, string passengerName,
           string flightNumber, string route,
           string seatNumber, double fare)
    {
        this->bookingId = bookingId;
        this->passengerName = passengerName;
        this->flightNumber = flightNumber;
        this->route = route;
        this->seatNumber = seatNumber;
        this->fare = fare;

        // Simple PNR generation suitable for a college project.
        pnr = "PNR" + to_string(bookingId);
    }

    string getPNR() const { return pnr; }

    void displayTicket() const
    {
        cout << "\n========================================\n";
        cout << "             FLIGHT TICKET\n";
        cout << "========================================\n";
        cout << "PNR            : " << pnr << endl;
        cout << "Booking ID     : " << bookingId << endl;
        cout << "Passenger      : " << passengerName << endl;
        cout << "Flight         : " << flightNumber << endl;
        cout << "Route          : " << route << endl;
        cout << "Seat           : " << seatNumber << endl;
        cout << "Fare           : Rs. " << fare << endl;
        cout << "========================================\n";
    }
};

#endif
