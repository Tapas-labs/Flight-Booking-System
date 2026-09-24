#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include <string.h>
using namespace std;

class Airport {
    char code[10],name[60],city[40],country[40];
public:
    Airport();
    Airport(const char c[],const char n[],const char ci[],const char co[]);
    void display();
};
#endif
