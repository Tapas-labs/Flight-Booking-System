#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include <string>
using namespace std;

/*
    Airport class
    -------------
    Stores basic information about an airport.
*/
class Airport
{
private:
    string code;       // Example: AMD
    string name;       // Example: Ahmedabad International Airport
    string city;
    string country;

public:
    Airport()
    {
        code = "";
        name = "";
        city = "";
        country = "";
    }

    Airport(string code, string name, string city, string country)
    {
        this->code = code;
        this->name = name;
        this->city = city;
        this->country = country;
    }

    string getCode() const { return code; }
    string getName() const { return name; }
    string getCity() const { return city; }
    string getCountry() const { return country; }

    void displayInfo() const
    {
        cout << code << " - " << name
             << " (" << city << ", " << country << ")" << endl;
    }
};

#endif
