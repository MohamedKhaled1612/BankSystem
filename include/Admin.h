#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include"Employee.h"
using namespace std ;
class Admin:public Employee
{
    public:
        Admin(int,string,string,double,double);
        void display() ;
        virtual ~Admin();

};

#endif // ADMIN_H
