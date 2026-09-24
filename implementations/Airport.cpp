#include "../classes/Airport.h"
Airport::Airport()
{
    strcpy(code,"");
    strcpy(name,"");
    strcpy(city,"");
    strcpy(country,"");
}
Airport::Airport(const char c[],const char n[],const char ci[],const char co[])
{
    strcpy(code,c);
    strcpy(name,n);
    strcpy(city,ci);
    strcpy(country,co);
}
void Airport::display()
{
    cout<<code<<" - "<<name<<", "<<city<<", "<<country<<"\n";
}
