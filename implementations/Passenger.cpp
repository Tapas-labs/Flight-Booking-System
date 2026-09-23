#include "../classes/Passenger.h"

Passenger::Passenger()
{
    passportNo = "";
    baggageAllowance = 20;
}

Passenger::Passenger(
    int id,
    string name,
    string email,
    string password,
    string phone,
    string passportNo,
    int baggageAllowance
) : User(id, name, email, password, phone)
{
    this->passportNo = passportNo;
    this->baggageAllowance = baggageAllowance;
}

void Passenger::displayProfile()
{
    cout << "\n========== PASSENGER PROFILE ==========\n";
    cout << "User ID            : " << userId << endl;
    cout << "Name               : " << name << endl;
    cout << "Email              : " << email << endl;
    cout << "Phone              : " << phone << endl;
    cout << "Passport Number    : " << passportNo << endl;
    cout << "Baggage Allowance  : " << baggageAllowance << " KG\n";
    cout << "=======================================\n";
}

void Passenger::searchFlight()
{
    cout << "\nFlight search is handled by the main menu.\n";
}

void Passenger::bookTicket()
{
    cout << "\nBooking is handled by the main menu.\n";
}

void Passenger::cancelTicket()
{
    cout << "\nCancellation is handled by the main menu.\n";
}

void Passenger::viewBookingHistory()
{
    cout << "\nBooking history is handled by the main menu.\n";
}

string Passenger::getPassportNo() const
{
    return passportNo;
}

int Passenger::getBaggageAllowance() const
{
    return baggageAllowance;
}
