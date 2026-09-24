#ifndef TICKET_H
#define TICKET_H
#include <iostream>
using namespace std;

class Ticket {
    int id,seat;
    char pnr[20],passenger[50],flight[20];
    double amount;
public:
    Ticket();
    Ticket(int i,const char p[],const char pa[],const char f[],int s,double a);
    void display();
};
#endif
