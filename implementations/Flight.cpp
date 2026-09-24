#include "../classes/Flight.h"
Flight::Flight()
{
    id=0;strcpy(number,"");
    strcpy(airline,"");
    strcpy(source,"");
    strcpy(destination,"");
    strcpy(departure,"");
    strcpy(arrival,"");
    fare=0;
    for(int i=0;i<20;i++)
    seats[i].setNumber(i+1);
}
Flight::Flight(int i,const char no[],const char air[],const char from[],const char to[],const char dep[],const char arr[],double f)
{
    id=i;
    strcpy(number,no);
    strcpy(airline,air);
    strcpy(source,from);
    strcpy(destination,to);
    strcpy(departure,dep);
    strcpy(arrival,arr);
    fare=f;
    for(int j=0;j<20;j++)
    seats[j].setNumber(j+1);
}
void Flight::display()
{
    cout<<"\nID: "<<id<<"\nFlight: "<<number<<"\nAirline: "<<airline<<"\nRoute: "<<source<<" -> "<<destination<<"\nDeparture: "<<departure<<"\nArrival: "<<arrival<<"\nFare: Rs. "<<fare<<"\n";
}
void Flight::showSeats()
{
    for(int i=0;i<20;i++)
    seats[i].display();
}
bool Flight::matches(const char from[],const char to[]){
    return strcmp(source,from)==0&&strcmp(destination,to)==0;
}
bool Flight::bookSeat(int n)
{
    if(n<1||n>20)return false;
    return seats[n-1].book();
}
void Flight::cancelSeat(int n)
{
    if(n>=1&&n<=20)
    seats[n-1].cancel();
}
bool Flight::seatAvailable(int n)
{
    return n>=1&&n<=20&&!seats[n-1].isBooked();
}
int Flight::getId()
{
    return id;
}
char* Flight::getNumber()
{
    return number;
}
char* Flight::getSource()
{
    return source;
}
char* Flight::getDestination()
{
    return destination;
}
char* Flight::getAirline()
{
    return airline;
}
char* Flight::getDeparture()
{
    return departure;
}
char* Flight::getArrival()
{
    return arrival;
}
double Flight::getFare()
{
    return fare;
}
