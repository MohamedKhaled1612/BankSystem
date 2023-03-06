#include "Employee.h"

Employee::Employee(int id=0,string name="",string password="",double balance=1500,double salary=5000):Client(id,name,password,balance)
{
    setSalary(salary);
}

Employee::~Employee()
{

}

double Employee::getSalary()
{
    return salary ;
}

void Employee::setSalary(double salary)
{
    this->salary = Validation::validateSalary(salary);
}

void Employee::display()
{
    Client::display() ;
    cout<<"Salary: " <<getSalary() <<endl;
}
