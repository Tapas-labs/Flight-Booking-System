#ifndef USER_H
#define USER_H
#include <iostream>
#include <string.h>
using namespace std;

class User {
protected:
    int userId;
    char name[50], email[50], password[30], phone[20];
public:
    User();
    User(int id,const char n[],const char e[],const char p[],const char ph[]);
    virtual ~User();
    bool login(const char e[],const char p[]);
    void logout();
    virtual void displayProfile()=0;
    int getUserId();
    char* getName();
    char* getEmail();
    char* getPassword();
    char* getPhone();
};
#endif
