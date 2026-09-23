#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

/*
    Admin class
    -----------
    Inherits User and represents the airline administrator.
*/
class Admin : public User
{
private:
    string employeeId;
    string role;

public:
    Admin();

    Admin(int id, string name, string email,
          string password, string phone,
          string employeeId, string role);

    void displayProfile() override;

    string getEmployeeId() const;
    string getRole() const;
};

#endif
