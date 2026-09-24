#include "../classes/Seat.h"
Seat::Seat()
{
    number=0;booked=0;
}
void Seat::setNumber(int n)
{
    number=n;
}
bool Seat::book()
{
    if(booked)return false;
    booked=1;
    return true;
}
void Seat::cancel(){
    booked=0;
}
bool Seat::isBooked()
{
    return booked==1;
}
void Seat::display()
{
    cout<<"Seat "<<number<<" : "<<(booked?"Booked":"Available")<<"\n";
}
