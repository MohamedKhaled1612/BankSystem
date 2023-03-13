#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include "Employee.h"
using namespace std ;
class Admin:public Employee
{
    public:
        Admin();
        Admin(int,string,string,double,double);
        void display() ;
        virtual ~Admin();
        void addEmployee(Employee) ;
        void listEmployee() ;
        void editEmployee(int, string, string, double, double) ;
        Employee searchEmployee(int id) ;

};

#endif // ADMIN_H
