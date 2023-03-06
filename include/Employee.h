#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include"Client.h"
#include "Validation.h"
using namespace std ;
class Employee:public Client
{
    double salary;
    public:
        Employee(int,string,string,double,double);
        virtual ~Employee();
        double getSalary();
        void setSalary(double);
        void display() ;
};

#endif // EMPLOYEE_H
