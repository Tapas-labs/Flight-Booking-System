#include "../classes/Admin.h"

Admin::Admin()
{
    employeeId = "";
    role = "Administrator";
}

Admin::Admin(int id, string name, string email,
             string password, string phone,
             string employeeId, string role)
    : User(id, name, email, password, phone)
{
    this->employeeId = employeeId;
    this->role = role;
}

void Admin::displayProfile()
{
    cout << "\n============== ADMIN PROFILE ==============\n";
    cout << "User ID       : " << userId << endl;
    cout << "Name          : " << name << endl;
    cout << "Email         : " << email << endl;
    cout << "Phone         : " << phone << endl;
    cout << "Employee ID   : " << employeeId << endl;
    cout << "Role          : " << role << endl;
    cout << "============================================\n";
}

string Admin::getEmployeeId() const
{
    return employeeId;
}

string Admin::getRole() const
{
    return role;
}
