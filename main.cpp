#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <algorithm>

#include "classes/User.h"
#include "classes/Passenger.h"
#include "classes/Admin.h"
#include "classes/Airport.h"
#include "classes/Flight.h"
#include "classes/Seat.h"
#include "classes/Booking.h"
#include "classes/Ticket.h"
#include "classes/Baggage.h"
#include "classes/Payment.h"

using namespace std;

/*
    ============================================================
    FLIGHT BOOKING SYSTEM - COMPLETE SIMPLE OOCP PROJECT
    ============================================================

    This project is intentionally kept simple.

    Main modules:
    1. User / Passenger / Admin
    2. Airport / Flight / Seat
    3. Booking / Ticket / Baggage
    4. Payment (UPI / Card / Cash)
    5. Simple file handling using .dat text files

    The main.cpp coordinates the application flow.
    Class files contain the actual object-oriented structure.
*/

// ------------------------------------------------------------
// Global data used by this simple console application
// ------------------------------------------------------------
vector<Flight> flights;
vector<Passenger> passengers;
vector<Booking> bookings;

const string FLIGHT_FILE = "data/flights.dat";
const string PASSENGER_FILE = "data/passengers.dat";
const string BOOKING_FILE = "data/bookings.dat";

// ------------------------------------------------------------
// Utility functions
// ------------------------------------------------------------

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string currentDate()
{
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", localTime);

    return string(buffer);
}

int getNextBookingId()
{
    int maxId = 1000;

    for (const Booking& b : bookings)
    {
        if (b.getBookingId() > maxId)
            maxId = b.getBookingId();
    }

    return maxId + 1;
}

int getNextPassengerId()
{
    int maxId = 100;

    for (const Passenger& p : passengers)
    {
        if (p.getUserId() > maxId)
            maxId = p.getUserId();
    }

    return maxId + 1;
}

// ------------------------------------------------------------
// File handling
// ------------------------------------------------------------

void saveFlights()
{
    ofstream file(FLIGHT_FILE);

    if (!file)
    {
        cout << "Unable to save flight data.\n";
        return;
    }

    /*
        Format:
        id|number|airline|source|destination|departure|arrival|seats|fare
    */

    for (const Flight& f : flights)
    {
        file << f.getFlightId() << "|"
             << f.getFlightNumber() << "|"
             << f.getAirline() << "|"
             << f.getSource() << "|"
             << f.getDestination() << "|"
             << f.getDepartureTime() << "|"
             << f.getArrivalTime() << "|"
             << f.getTotalSeats() << "|"
             << f.getBaseFare() << "\n";
    }
}

void loadFlights()
{
    ifstream file(FLIGHT_FILE);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        string id, number, airline, source, destination;
        string departure, arrival, seatsText, fareText;

        getline(ss, id, '|');
        getline(ss, number, '|');
        getline(ss, airline, '|');
        getline(ss, source, '|');
        getline(ss, destination, '|');
        getline(ss, departure, '|');
        getline(ss, arrival, '|');
        getline(ss, seatsText, '|');
        getline(ss, fareText, '|');

        if (!id.empty())
        {
            flights.push_back(
                Flight(
                    id,
                    number,
                    airline,
                    source,
                    destination,
                    departure,
                    arrival,
                    stoi(seatsText),
                    stod(fareText)
                )
            );
        }
    }
}

void savePassengers()
{
    ofstream file(PASSENGER_FILE);

    if (!file)
    {
        cout << "Unable to save passenger data.\n";
        return;
    }

    /*
        Format:
        id|name|email|password|phone|passport|allowance
    */

    for (const Passenger& p : passengers)
    {
        file << p.getUserId() << "|"
             << p.getName() << "|"
             << p.getEmail() << "|"
             << "1234" << "|"
             << p.getPhone() << "|"
             << p.getPassportNo() << "|"
             << p.getBaggageAllowance() << "\n";
    }
}

void loadPassengers()
{
    ifstream file(PASSENGER_FILE);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idText, name, email, password;
        string phone, passport, allowanceText;

        getline(ss, idText, '|');
        getline(ss, name, '|');
        getline(ss, email, '|');
        getline(ss, password, '|');
        getline(ss, phone, '|');
        getline(ss, passport, '|');
        getline(ss, allowanceText, '|');

        if (!idText.empty())
        {
            passengers.push_back(
                Passenger(
                    stoi(idText),
                    name,
                    email,
                    password,
                    phone,
                    passport,
                    stoi(allowanceText)
                )
            );
        }
    }
}

void saveBookings()
{
    ofstream file(BOOKING_FILE);

    if (!file)
    {
        cout << "Unable to save booking data.\n";
        return;
    }

    /*
        Format:
        bookingId|passengerId|flightId|seat|date|baggage|amount|status
    */

    for (const Booking& b : bookings)
    {
        file << b.getBookingId() << "|"
             << b.getPassengerId() << "|"
             << b.getFlightId() << "|"
             << b.getSeatNumber() << "|"
             << b.getBookingDate() << "|"
             << b.getBaggageWeight() << "|"
             << b.getTotalAmount() << "|"
             << b.getStatus() << "\n";
    }
}

void loadBookings()
{
    ifstream file(BOOKING_FILE);

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        stringstream ss(line);

        string idText, passengerText, flightId, seat;
        string date, baggageText, amountText, status;

        getline(ss, idText, '|');
        getline(ss, passengerText, '|');
        getline(ss, flightId, '|');
        getline(ss, seat, '|');
        getline(ss, date, '|');
        getline(ss, baggageText, '|');
        getline(ss, amountText, '|');
        getline(ss, status, '|');

        if (!idText.empty())
        {
            bookings.push_back(
                Booking(
                    stoi(idText),
                    stoi(passengerText),
                    flightId,
                    seat,
                    date,
                    stod(baggageText),
                    stod(amountText),
                    status
                )
            );
        }
    }
}

// ------------------------------------------------------------
// Sample flight data
// ------------------------------------------------------------

void createDefaultFlights()
{
    if (!flights.empty())
        return;

    flights.push_back(
        Flight(
            "F101",
            "AI203",
            "Air India",
            "Ahmedabad",
            "Delhi",
            "10:30 AM",
            "12:15 PM",
            20,
            4500
        )
    );

    flights.push_back(
        Flight(
            "F102",
            "6E501",
            "IndiGo",
            "Ahmedabad",
            "Mumbai",
            "02:00 PM",
            "03:20 PM",
            20,
            3200
        )
    );

    flights.push_back(
        Flight(
            "F103",
            "6E701",
            "IndiGo",
            "Delhi",
            "Bangalore",
            "08:00 AM",
            "10:40 AM",
            20,
            5200
        )
    );

    saveFlights();
}

// ------------------------------------------------------------
// Passenger registration
// ------------------------------------------------------------

void registerPassenger()
{
    string name, email, password, phone, passport;
    int allowance;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n========== PASSENGER REGISTRATION ==========\n";

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Create Password: ";
    getline(cin, password);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter Passport Number: ";
    getline(cin, passport);

    cout << "Enter Baggage Allowance (KG): ";
    cin >> allowance;

    int id = getNextPassengerId();

    passengers.push_back(
        Passenger(
            id,
            name,
            email,
            password,
            phone,
            passport,
            allowance
        )
    );

    savePassengers();

    cout << "\nRegistration Successful!\n";
    cout << "Your Passenger ID is: " << id << endl;
}

// ------------------------------------------------------------
// Find passenger by email
// ------------------------------------------------------------

Passenger* findPassenger(string email)
{
    for (Passenger& p : passengers)
    {
        if (p.getEmail() == email)
            return &p;
    }

    return nullptr;
}

// ------------------------------------------------------------
// Display all flights
// ------------------------------------------------------------

void displayAllFlights()
{
    if (flights.empty())
    {
        cout << "\nNo flights available.\n";
        return;
    }

    cout << "\n========== AVAILABLE FLIGHTS ==========\n";

    for (const Flight& f : flights)
        f.displayDetails();
}

// ------------------------------------------------------------
// Search flights
// ------------------------------------------------------------

void searchFlights()
{
    string source, destination;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter Source: ";
    getline(cin, source);

    cout << "Enter Destination: ";
    getline(cin, destination);

    bool found = false;

    for (const Flight& f : flights)
    {
        if (f.getSource() == source &&
            f.getDestination() == destination)
        {
            f.displayDetails();
            found = true;
        }
    }

    if (!found)
        cout << "\nNo matching flight found.\n";
}

// ------------------------------------------------------------
// Find flight by ID
// ------------------------------------------------------------

Flight* findFlight(string id)
{
    for (Flight& f : flights)
    {
        if (f.getFlightId() == id)
            return &f;
    }

    return nullptr;
}

// ------------------------------------------------------------
// Display passenger bookings
// ------------------------------------------------------------

void displayPassengerBookings(int passengerId)
{
    bool found = false;

    cout << "\n========== YOUR BOOKINGS ==========\n";

    for (const Booking& b : bookings)
    {
        if (b.getPassengerId() == passengerId)
        {
            b.displayBookingDetails();
            found = true;
        }
    }

    if (!found)
        cout << "No bookings found.\n";
}

// ------------------------------------------------------------
// Book a flight
// ------------------------------------------------------------

void bookFlight(Passenger& passenger)
{
    displayAllFlights();

    string flightId;
    cout << "\nEnter Flight ID: ";
    cin >> flightId;

    Flight* flight = findFlight(flightId);

    if (flight == nullptr)
    {
        cout << "\nFlight not found.\n";
        return;
    }

    flight->displaySeats();

    string seatNumber;
    cout << "\nEnter Seat Number: ";
    cin >> seatNumber;

    if (!flight->isSeatAvailable(seatNumber))
    {
        cout << "\nSeat is not available or does not exist.\n";
        return;
    }

    double baggageWeight;

    cout << "Enter total baggage weight (KG): ";
    cin >> baggageWeight;

    // Calculate extra baggage charges.
    Baggage baggage(
        1,
        baggageWeight,
        passenger.getBaggageAllowance()
    );

    double baggageCharge = baggage.getExtraCharge();

    // Simple seat charge for window seat.
    // To keep the project simple, we do not inspect seat type here.
    double seatCharge = 0;

    double total = flight->getBaseFare()
                 + baggageCharge
                 + seatCharge;

    cout << fixed << setprecision(2);

    cout << "\n========== FARE SUMMARY ==========\n";
    cout << "Base Fare       : Rs. " << flight->getBaseFare() << endl;
    cout << "Baggage Charge  : Rs. " << baggageCharge << endl;
    cout << "Seat Charge     : Rs. " << seatCharge << endl;
    cout << "Total           : Rs. " << total << endl;
    cout << "==================================\n";

    cout << "\nSelect Payment Method:\n";
    cout << "1. UPI\n";
    cout << "2. Card\n";
    cout << "3. Cash\n";
    cout << "Enter Choice: ";

    int paymentChoice;
    cin >> paymentChoice;

    Payment* payment = nullptr;

    string date = currentDate();

    if (paymentChoice == 1)
    {
        string upi;
        cout << "Enter UPI ID: ";
        cin >> upi;

        payment = new UPIPayment(
            1,
            total,
            date,
            upi
        );
    }
    else if (paymentChoice == 2)
    {
        string cardNumber, holder;

        cout << "Enter Card Number: ";
        cin >> cardNumber;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Card Holder Name: ";
        getline(cin, holder);

        payment = new CardPayment(
            1,
            total,
            date,
            cardNumber,
            holder
        );
    }
    else if (paymentChoice == 3)
    {
        payment = new CashPayment(
            1,
            total,
            date
        );
    }
    else
    {
        cout << "\nInvalid payment method.\n";
        return;
    }

    // Runtime polymorphism:
    // Payment pointer calls the correct child class pay().
    bool paymentSuccess = payment->pay();

    delete payment;

    if (!paymentSuccess)
    {
        cout << "\nPayment failed. Booking cancelled.\n";
        return;
    }

    // Only book the seat after successful payment.
    if (!flight->bookSeat(seatNumber))
    {
        cout << "\nSeat could not be booked.\n";
        return;
    }

    int bookingId = getNextBookingId();

    Booking newBooking(
        bookingId,
        passenger.getUserId(),
        flight->getFlightId(),
        seatNumber,
        currentDate(),
        baggageWeight,
        total,
        "Confirmed"
    );

    bookings.push_back(newBooking);
    saveBookings();

    cout << "\nBooking Confirmed Successfully!\n";

    Ticket ticket(
        bookingId,
        passenger.getName(),
        flight->getFlightNumber(),
        flight->getSource() + " -> " + flight->getDestination(),
        seatNumber,
        total
    );

    ticket.displayTicket();
}

// ------------------------------------------------------------
// Cancel booking
// ------------------------------------------------------------

void cancelBooking(Passenger& passenger)
{
    displayPassengerBookings(passenger.getUserId());

    int bookingId;

    cout << "\nEnter Booking ID to cancel: ";
    cin >> bookingId;

    for (Booking& b : bookings)
    {
        if (b.getBookingId() == bookingId &&
            b.getPassengerId() == passenger.getUserId())
        {
            if (b.getStatus() == "Cancelled")
            {
                cout << "\nBooking is already cancelled.\n";
                return;
            }

            Flight* flight = findFlight(b.getFlightId());

            if (flight != nullptr)
                flight->cancelSeat(b.getSeatNumber());

            b.setStatus("Cancelled");

            saveBookings();

            cout << "\nBooking cancelled successfully.\n";
            return;
        }
    }

    cout << "\nBooking not found.\n";
}

// ------------------------------------------------------------
// Passenger menu
// ------------------------------------------------------------

void passengerMenu(Passenger& passenger)
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "          PASSENGER MENU\n";
        cout << "========================================\n";
        cout << "1. View Profile\n";
        cout << "2. View All Flights\n";
        cout << "3. Search Flight\n";
        cout << "4. Book Flight\n";
        cout << "5. View Booking History\n";
        cout << "6. Cancel Booking\n";
        cout << "7. Logout\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            passenger.displayProfile();
            break;

        case 2:
            displayAllFlights();
            break;

        case 3:
            searchFlights();
            break;

        case 4:
            bookFlight(passenger);
            break;

        case 5:
            displayPassengerBookings(passenger.getUserId());
            break;

        case 6:
            cancelBooking(passenger);
            break;

        case 7:
            passenger.logout();
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 7);
}

// ------------------------------------------------------------
// Passenger login
// ------------------------------------------------------------

void passengerLogin()
{
    string email, password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n========== PASSENGER LOGIN ==========\n";

    cout << "Email: ";
    getline(cin, email);

    cout << "Password: ";
    getline(cin, password);

    Passenger* passenger = findPassenger(email);

    if (passenger == nullptr)
    {
        cout << "\nPassenger not found. Please register first.\n";
        return;
    }

    if (passenger->login(email, password))
    {
        passengerMenu(*passenger);
    }
}

// ------------------------------------------------------------
// Admin functions
// ------------------------------------------------------------

void adminAddFlight()
{
    string id, number, airline, source, destination;
    string departure, arrival;
    int seats;
    double fare;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n========== ADD FLIGHT ==========\n";

    cout << "Flight ID: ";
    getline(cin, id);

    if (findFlight(id) != nullptr)
    {
        cout << "Flight ID already exists.\n";
        return;
    }

    cout << "Flight Number: ";
    getline(cin, number);

    cout << "Airline: ";
    getline(cin, airline);

    cout << "Source: ";
    getline(cin, source);

    cout << "Destination: ";
    getline(cin, destination);

    cout << "Departure Time: ";
    getline(cin, departure);

    cout << "Arrival Time: ";
    getline(cin, arrival);

    cout << "Total Seats (max 20 in this simple version): ";
    cin >> seats;

    if (seats < 1)
    {
        cout << "Invalid number of seats.\n";
        return;
    }

    cout << "Base Fare: ";
    cin >> fare;

    flights.push_back(
        Flight(
            id,
            number,
            airline,
            source,
            destination,
            departure,
            arrival,
            seats,
            fare
        )
    );

    saveFlights();

    cout << "\nFlight added successfully.\n";
}

void adminRemoveFlight()
{
    string id;

    cout << "\nEnter Flight ID to remove: ";
    cin >> id;

    for (auto it = flights.begin(); it != flights.end(); ++it)
    {
        if (it->getFlightId() == id)
        {
            flights.erase(it);
            saveFlights();

            cout << "\nFlight removed successfully.\n";
            return;
        }
    }

    cout << "\nFlight not found.\n";
}

void adminViewBookings()
{
    if (bookings.empty())
    {
        cout << "\nNo bookings available.\n";
        return;
    }

    cout << "\n========== ALL BOOKINGS ==========\n";

    for (const Booking& b : bookings)
        b.displayBookingDetails();
}

void adminMenu()
{
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "             ADMIN MENU\n";
        cout << "========================================\n";
        cout << "1. View All Flights\n";
        cout << "2. Add Flight\n";
        cout << "3. Remove Flight\n";
        cout << "4. View All Bookings\n";
        cout << "5. Logout\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllFlights();
            break;

        case 2:
            adminAddFlight();
            break;

        case 3:
            adminRemoveFlight();
            break;

        case 4:
            adminViewBookings();
            break;

        case 5:
            cout << "\nAdmin logged out.\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 5);
}

// ------------------------------------------------------------
// Admin login
// ------------------------------------------------------------

void adminLogin()
{
    string email, password;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n========== ADMIN LOGIN ==========\n";

    cout << "Email: ";
    getline(cin, email);

    cout << "Password: ";
    getline(cin, password);

    /*
        For a simple college project we use one fixed admin account.
        Real applications should use a proper database/authentication system.
    */
    Admin admin(
        1,
        "System Admin",
        "admin@airline.com",
        "admin123",
        "9999999999",
        "ADM001",
        "Flight Manager"
    );

    if (admin.login(email, password))
    {
        admin.displayProfile();
        adminMenu();
    }
}

// ------------------------------------------------------------
// Main menu
// ------------------------------------------------------------

int main()
{
    // Load existing data from files.
    loadFlights();
    loadPassengers();
    loadBookings();

    // If no flight file exists, create a few sample flights.
    createDefaultFlights();

    int choice;

    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "        FLIGHT BOOKING SYSTEM\n";
        cout << "        C++ OOCP PROJECT\n";
        cout << "============================================\n";
        cout << "1. Passenger Registration\n";
        cout << "2. Passenger Login\n";
        cout << "3. Admin Login\n";
        cout << "4. View Flights\n";
        cout << "5. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "Enter Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            registerPassenger();
            break;

        case 2:
            passengerLogin();
            break;

        case 3:
            adminLogin();
            break;

        case 4:
            displayAllFlights();
            break;

        case 5:
            cout << "\nThank you for using Flight Booking System!\n";
            break;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 5);

    // Save data before closing.
    saveFlights();
    savePassengers();
    saveBookings();

    return 0;
}
