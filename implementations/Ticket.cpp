#include "../classes/Ticket.h"
#include <string.h>
Ticket::Ticket()
{
    id=0;
    seat=0;
    amount=0;
    strcpy(pnr,"");
    strcpy(passenger,"");
    strcpy(flight,"");
}
Ticket::Ticket(int i,const char p[],const char pa[],const char f[],int s,double a)
{
    id=i;strcpy(pnr,p);
    strcpy(passenger,pa);
    strcpy(flight,f);
    seat=s;amount=a;
}
void Ticket::display()
{
    cout<<"\n========== TICKET ==========\nTicket ID: "<<id<<"\nPNR: "<<pnr<<"\nPassenger: "<<passenger<<"\nFlight: "<<flight<<"\nSeat: "<<seat<<"\nAmount: Rs. "<<amount<<"\n============================\n";
}
