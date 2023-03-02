#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include"Person.h"
using namespace std ;
class Employee:public Person
{
    double salary;
    public:
        Employee(int,string,string,double);
        virtual ~Employee();
        double getSalary();
        void setSalary(double);
        void display() ;
};

#endif // EMPLOYEE_H
