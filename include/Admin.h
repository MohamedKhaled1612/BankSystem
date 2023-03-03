#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"Emplyoee.h"
using namespace std ;
class Admin:public Employee
{
    public:
        Admin(int,string,string,double);
        virtual ~Admin();

};

#endif // ADMIN_H
