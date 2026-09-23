#ifndef BAGGAGE_H
#define BAGGAGE_H

#include <iostream>
using namespace std;

/*
    Baggage class
    -------------
    Handles simple extra baggage calculation.

    Default passenger allowance = 20 KG.
    Extra baggage is charged at Rs. 80 per KG.
*/
class Baggage
{
private:
    int baggageId;
    double weight;
    double allowedWeight;
    double extraCharge;

public:
    Baggage()
    {
        baggageId = 0;
        weight = 0;
        allowedWeight = 20;
        extraCharge = 0;
    }

    Baggage(int id, double weight, double allowedWeight = 20)
    {
        baggageId = id;
        this->weight = weight;
        this->allowedWeight = allowedWeight;
        extraCharge = calculateCharge();
    }

    double calculateCharge() const
    {
        if (weight <= allowedWeight)
            return 0;

        return (weight - allowedWeight) * 80;
    }

    double getWeight() const { return weight; }
    double getExtraCharge() const { return extraCharge; }

    void displayBaggage() const
    {
        cout << "Baggage Weight : " << weight << " KG\n";
        cout << "Allowed Weight : " << allowedWeight << " KG\n";
        cout << "Extra Charge   : Rs. " << extraCharge << endl;
    }
};

#endif
