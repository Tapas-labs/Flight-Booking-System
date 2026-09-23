#include "../classes/User.h"

User::User()
{
    userId = 0;
    name = "";
    email = "";
    password = "";
    phone = "";
}

User::User(int id, string name, string email,
           string password, string phone)
{
    this->userId = id;
    this->name = name;
    this->email = email;
    this->password = password;
    this->phone = phone;
}

User::~User()
{
}

bool User::login(string email, string password)
{
    if (this->email == email && this->password == password)
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    cout << "\nInvalid Email or Password!\n";
    return false;
}

void User::logout()
{
    cout << "\n" << name << " logged out successfully.\n";
}

int User::getUserId() const
{
    return userId;
}

string User::getName() const
{
    return name;
}

string User::getEmail() const
{
    return email;
}

string User::getPhone() const
{
    return phone;
}
