#include "../classes/Admin.h"
Admin::Admin():User()
{
    strcpy(employeeId,"");
    strcpy(role,"Administrator");
}
Admin::Admin(int id,const char n[],const char e[],const char p[],const char ph[],const char emp[],const char r[]):User(id,n,e,p,ph)
{
    strcpy(employeeId,emp);
    strcpy(role,r);
}
void Admin::displayProfile()
{
    cout<<"\n--- Admin Profile ---\nID: "<<userId<<"\nName: "<<name<<"\nEmail: "<<email<<"\nEmployee ID: "<<employeeId<<"\nRole: "<<role<<"\n";
}
