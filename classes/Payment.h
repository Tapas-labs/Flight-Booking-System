#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string.h>
using namespace std;

class Payment {
protected:
    double amount;
public:
    Payment(double a);
    virtual ~Payment();
    virtual void pay()=0;
};
class UPIPayment:public Payment {
    char upi[50];
public:
    UPIPayment(double a,const char u[]);
    void pay();
};
class CardPayment:public Payment {
    char card[30];
public:
    CardPayment(double a,const char c[]);
    void pay();
};
class CashPayment:public Payment {
public:
    CashPayment(double a);
    void pay();
};
#endif
