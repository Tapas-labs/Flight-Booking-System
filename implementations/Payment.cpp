#include "../classes/Payment.h"
Payment::Payment(double a)
{
    amount=a;
}
Payment::~Payment(){}
UPIPayment::UPIPayment(double a,const char u[]):Payment(a)
{
    strcpy(upi,u);
}
void UPIPayment::pay()
{
    cout<<"UPI payment successful. Amount: Rs. "<<amount<<"\n";
}
CardPayment::CardPayment(double a,const char c[]):Payment(a)
{
    strcpy(card,c);
}
void CardPayment::pay()
{
    cout<<"Card payment successful. Amount: Rs. "<<amount<<"\n";
}
CashPayment::CashPayment(double a):Payment(a){}
void CashPayment::pay()
{
    cout<<"Cash payment accepted. Amount: Rs. "<<amount<<"\n";
}
