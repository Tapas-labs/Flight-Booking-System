#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;

/*
    Seat class
    ----------
    Represents one seat inside a flight.

    We keep this class simple because this is a college OOCP project.
    It demonstrates encapsulation and basic class/object usage.
*/
class Seat
{
private:
    string seatNumber;   // Example: 1A, 1B, 2A
    string seatClass;    // Economy / Business
    string seatType;     // Window / Middle / Aisle
    bool booked;         // true = already booked

public:
    Seat()
    {
        seatNumber = "";
        seatClass = "Economy";
        seatType = "Window";
        booked = false;
    }

    Seat(string number, string sClass, string type)
    {
        seatNumber = number;
        seatClass = sClass;
        seatType = type;
        booked = false;
    }

    string getSeatNumber() const { return seatNumber; }
    string getSeatClass() const { return seatClass; }
    string getSeatType() const { return seatType; }
    bool isBooked() const { return booked; }

    bool bookSeat()
    {
        if (booked)
            return false;

        booked = true;
        return true;
    }

    void cancelSeat()
    {
        booked = false;
    }

    void displaySeat() const
    {
        cout << seatNumber << " - "
             << seatClass << " - "
             << seatType << " - "
             << (booked ? "Booked" : "Available") << endl;
    }
};

#endif
