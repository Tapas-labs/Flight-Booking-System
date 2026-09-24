#include "../classes/User.h"
User::User()
{
    userId=0;
    strcpy(name,"");
    strcpy(email,"");
    strcpy(password,"");
    strcpy(phone,"");
}
User::User(int id,const char n[],const char e[],const char p[],const char ph[])
{
    userId=id;
    strcpy(name,n);
    strcpy(email,e);
    strcpy(password,p);
    strcpy(phone,ph);
}
User::~User(){}
bool User::login(const char e[],const char p[])
{
    return strcmp(email,e)==0 && strcmp(password,p)==0;
}
void User::logout()
{
    cout<<name<<" logged out successfully.\n";
}
void User::displayProfile(){}
int User::getUserId()
{
    return userId;
}
char* User::getName()
{
    return name;
}
char* User::getEmail()
{
    return email;
}
char* User::getPassword()
{
    return password;
}
char* User::getPhone()
{
    return phone;
}
