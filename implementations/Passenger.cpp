#include "../classes/Passenger.h"
Passenger::Passenger():User()
{
    strcpy(passportNo,"");
    baggageAllowance=20;
}
Passenger::Passenger(int id,const char n[],const char e[],const char p[],const char ph[],const char pass[],int bag):User(id,n,e,p,ph)
{
    strcpy(passportNo,pass);
    baggageAllowance=bag;
}
void Passenger::displayProfile()
{
    cout<<"\n--- Passenger Profile ---\nID: "<<userId<<"\nName: "<<name<<"\nEmail: "<<email<<"\nPhone: "<<phone<<"\nPassport: "<<passportNo<<"\nBaggage: "<<baggageAllowance<<" KG\n";
}
char* Passenger::getPassportNo()
{
    return passportNo;
}
int Passenger::getBaggageAllowance()
{
    return baggageAllowance;
}
