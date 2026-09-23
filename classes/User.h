#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

/*
    Abstract User class
    -------------------
    Common parent class for Passenger and Admin.

    OOP concepts:
    - Abstraction: displayProfile() is pure virtual.
    - Inheritance: Passenger/Admin inherit from User.
    - Encapsulation: common data is protected/private.
    - Polymorphism: derived classes override displayProfile().
*/
class User
{
protected:
    int userId;
    string name;
    string email;
    string password;
    string phone;

public:
    User();
    User(int id, string name, string email, string password, string phone);

    virtual ~User();

    // Pure virtual function makes User an abstract class.
    virtual void displayProfile() = 0;

    bool login(string email, string password);
    void logout();

    int getUserId() const;
    string getName() const;
    string getEmail() const;
    string getPhone() const;
};

#endif
