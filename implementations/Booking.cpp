#include "../classes/Booking.h"
Booking::Booking()
{
    id=0;
    passengerId=0;
    flightId=0;
    seat=0;
    amount=0;
    strcpy(passenger,"");
    strcpy(flight,"");
    strcpy(status,"Cancelled");
    strcpy(pnr,"");
}
Booking::Booking(int i,int pi,int fi,int s,const char pa[],const char fl[],double a,const char p[])
{
    id=i;
    passengerId=pi;
    flightId=fi;
    seat=s;
    strcpy(passenger,pa);
    strcpy(flight,fl);
    amount=a;
    strcpy(status,"Confirmed");
    strcpy(pnr,p);
}
void Booking::cancel()
{
    strcpy(status,"Cancelled");
}
void Booking::display()
{
    cout<<"\nBooking ID: "<<id<<"\nPassenger: "<<passenger<<"\nFlight: "<<flight<<"\nSeat: "<<seat<<"\nAmount: Rs. "<<amount<<"\nPNR: "<<pnr<<"\nStatus: "<<status<<"\n";
}
int Booking::getId()
{
    return id;
}
int Booking::getPassengerId()
{
    return passengerId;
}
int Booking::getFlightId()
{
    return flightId;
}
int Booking::getSeat()
{
    return seat;
}
double Booking::getAmount()
{
    return amount;
}
char* Booking::getPNR()
{
    return pnr;
}
char* Booking::getStatus()
{
    return status;
}
char* Booking::getPassengerName()
{
    return passenger;
}
char* Booking::getFlightNumber()
{
    return flight;
}
