#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<fstream>
#include"Client.h"
#include "Validation.h"
using namespace std ;
class Employee:public Client
{
    double salary;
    public:
        Employee() ;
        Employee(int,string,string,double,double);
        virtual ~Employee();
        double getSalary();
        void setSalary(double);
        void display();
        void addClient(Client) ;
        void listClient() ;
        void editClient(int, string, string, double) ;
        Client searchClient(int id) ;
};

#endif // EMPLOYEE_H
