#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

/*
    Flight class
    ------------
    Stores flight information and its seats.

    OOP concepts:
    - Encapsulation: data members are private.
    - Composition: a Flight contains Seat objects.
*/
class Flight
{
private:
    string flightId;
    string flightNumber;
    string airline;
    string source;
    string destination;
    string departureTime;
    string arrivalTime;
    int totalSeats;
    double baseFare;

    vector<Seat> seats;   // Seats belonging to this flight

public:
    Flight()
    {
        flightId = "";
        flightNumber = "";
        airline = "";
        source = "";
        destination = "";
        departureTime = "";
        arrivalTime = "";
        totalSeats = 0;
        baseFare = 0;
    }

    Flight(string id, string number, string airline,
           string source, string destination,
           string departure, string arrival,
           int totalSeats, double fare)
    {
        flightId = id;
        flightNumber = number;
        this->airline = airline;
        this->source = source;
        this->destination = destination;
        departureTime = departure;
        arrivalTime = arrival;
        this->totalSeats = totalSeats;
        baseFare = fare;

        // Create simple seats automatically.
        // For this project we use 20 seats max for easy demonstration.
        int seatCount = totalSeats;
        if (seatCount > 20)
            seatCount = 20;

        for (int i = 1; i <= seatCount; i++)
        {
            char rowLetter = 'A' + ((i - 1) % 4);
            int row = ((i - 1) / 4) + 1;

            string number = to_string(row) + rowLetter;
            string type;

            if (rowLetter == 'A' || rowLetter == 'D')
                type = "Window";
            else if (rowLetter == 'B')
                type = "Middle";
            else
                type = "Aisle";

            seats.push_back(Seat(number, "Economy", type));
        }
    }

    string getFlightId() const { return flightId; }
    string getFlightNumber() const { return flightNumber; }
    string getAirline() const { return airline; }
    string getSource() const { return source; }
    string getDestination() const { return destination; }
    string getDepartureTime() const { return departureTime; }
    string getArrivalTime() const { return arrivalTime; }
    int getTotalSeats() const { return totalSeats; }
    double getBaseFare() const { return baseFare; }

    void displayDetails() const
    {
        cout << "\n----------------------------------------\n";
        cout << "Flight ID      : " << flightId << endl;
        cout << "Flight Number  : " << flightNumber << endl;
        cout << "Airline        : " << airline << endl;
        cout << "Route          : " << source << " -> " << destination << endl;
        cout << "Departure      : " << departureTime << endl;
        cout << "Arrival        : " << arrivalTime << endl;
        cout << "Total Seats    : " << totalSeats << endl;
        cout << "Available      : " << getAvailableSeats() << endl;
        cout << "Base Fare      : Rs. " << baseFare << endl;
        cout << "----------------------------------------\n";
    }

    int getAvailableSeats() const
    {
        int count = 0;
        for (const Seat& seat : seats)
        {
            if (!seat.isBooked())
                count++;
        }
        return count;
    }

    bool isSeatAvailable(string number) const
    {
        for (const Seat& seat : seats)
        {
            if (seat.getSeatNumber() == number)
                return !seat.isBooked();
        }
        return false;
    }

    bool bookSeat(string number)
    {
        for (Seat& seat : seats)
        {
            if (seat.getSeatNumber() == number)
                return seat.bookSeat();
        }
        return false;
    }

    bool cancelSeat(string number)
    {
        for (Seat& seat : seats)
        {
            if (seat.getSeatNumber() == number)
            {
                seat.cancelSeat();
                return true;
            }
        }
        return false;
    }

    void displaySeats() const
    {
        cout << "\nSeats for " << flightNumber << ":\n";
        for (const Seat& seat : seats)
            seat.displaySeat();
    }

    // Used when the program saves/loads the flight.
    // Seat booking status is intentionally not persisted in this simple version;
    // the booking file is the source of truth for completed bookings.
};

#endif
