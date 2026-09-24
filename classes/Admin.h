#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"

class Admin:public User {
    char employeeId[20],role[30];
public:
    Admin();
    Admin(int id,const char n[],const char e[],const char p[],const char ph[],const char emp[],const char r[]);
    void displayProfile();
};
#endif
