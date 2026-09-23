#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <string>
using namespace std;

/*
    Payment - abstract base class
    ------------------------------
    Demonstrates abstraction and runtime polymorphism.

    UPI, Card and Cash provide their own pay() implementation.
*/
class Payment
{
protected:
    int paymentId;
    double amount;
    string paymentDate;
    string status;

public:
    Payment()
    {
        paymentId = 0;
        amount = 0;
        paymentDate = "";
        status = "Pending";
    }

    Payment(int id, double amount, string date)
    {
        paymentId = id;
        this->amount = amount;
        paymentDate = date;
        status = "Pending";
    }

    virtual ~Payment() {}

    virtual bool pay() = 0;

    string getStatus() const { return status; }
    double getAmount() const { return amount; }
};

class UPIPayment : public Payment
{
private:
    string upiId;

public:
    UPIPayment(int id, double amount, string date, string upi)
        : Payment(id, amount, date)
    {
        upiId = upi;
    }

    bool pay() override
    {
        cout << "\nProcessing UPI payment...\n";
        cout << "UPI ID: " << upiId << endl;
        cout << "Amount: Rs. " << amount << endl;

        status = "Paid";
        cout << "UPI Payment Successful!\n";
        return true;
    }
};

class CardPayment : public Payment
{
private:
    string cardNumber;
    string cardHolder;

public:
    CardPayment(int id, double amount, string date,
                string cardNumber, string cardHolder)
        : Payment(id, amount, date)
    {
        this->cardNumber = cardNumber;
        this->cardHolder = cardHolder;
    }

    bool pay() override
    {
        cout << "\nProcessing Card payment...\n";
        cout << "Card Holder: " << cardHolder << endl;
        cout << "Amount: Rs. " << amount << endl;

        status = "Paid";
        cout << "Card Payment Successful!\n";
        return true;
    }
};

class CashPayment : public Payment
{
public:
    CashPayment(int id, double amount, string date)
        : Payment(id, amount, date)
    {
    }

    bool pay() override
    {
        cout << "\nProcessing Cash payment...\n";
        cout << "Amount: Rs. " << amount << endl;

        status = "Paid";
        cout << "Cash Payment Successful!\n";
        return true;
    }
};

#endif
