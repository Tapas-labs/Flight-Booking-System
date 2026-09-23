#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
    Booking class
    -------------
    Stores the details of one ticket reservation.

    A Booking connects:
    Passenger + Flight + Seat + Baggage + Payment
*/
class Booking
{
private:
    int bookingId;
    int passengerId;
    string flightId;
    string seatNumber;
    string bookingDate;
    double baggageWeight;
    double totalAmount;
    string status;

public:
    Booking()
    {
        bookingId = 0;
        passengerId = 0;
        flightId = "";
        seatNumber = "";
        bookingDate = "";
        baggageWeight = 0;
        totalAmount = 0;
        status = "Pending";
    }

    Booking(int bookingId, int passengerId, string flightId,
            string seatNumber, string bookingDate,
            double baggageWeight, double totalAmount,
            string status)
    {
        this->bookingId = bookingId;
        this->passengerId = passengerId;
        this->flightId = flightId;
        this->seatNumber = seatNumber;
        this->bookingDate = bookingDate;
        this->baggageWeight = baggageWeight;
        this->totalAmount = totalAmount;
        this->status = status;
    }

    int getBookingId() const { return bookingId; }
    int getPassengerId() const { return passengerId; }
    string getFlightId() const { return flightId; }
    string getSeatNumber() const { return seatNumber; }
    string getBookingDate() const { return bookingDate; }
    double getBaggageWeight() const { return baggageWeight; }
    double getTotalAmount() const { return totalAmount; }
    string getStatus() const { return status; }

    void setStatus(string newStatus)
    {
        status = newStatus;
    }

    void displayBookingDetails() const
    {
        cout << fixed << setprecision(2);
        cout << "\n========== BOOKING DETAILS ==========\n";
        cout << "Booking ID       : " << bookingId << endl;
        cout << "Passenger ID     : " << passengerId << endl;
        cout << "Flight ID        : " << flightId << endl;
        cout << "Seat             : " << seatNumber << endl;
        cout << "Booking Date     : " << bookingDate << endl;
        cout << "Extra Baggage    : " << baggageWeight << " KG" << endl;
        cout << "Total Amount     : Rs. " << totalAmount << endl;
        cout << "Status           : " << status << endl;
        cout << "=====================================\n";
    }
};

#endif
