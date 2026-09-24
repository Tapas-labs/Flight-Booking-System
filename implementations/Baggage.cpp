#include "../classes/Baggage.h"
Baggage::Baggage()
{
    weight=0;charge=0;
}
Baggage::Baggage(int w)
{
    weight=w;calculate();
}
void Baggage::calculate()
{
    charge=weight>20?(weight-20)*80:0;
}
void Baggage::display()
{
    cout<<"Baggage: "<<weight<<" KG, Extra charge: Rs. "<<charge<<"\n";
}
double Baggage::getCharge()
{
    return charge;
}
