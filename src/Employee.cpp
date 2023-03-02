#include "Employee.h"
#include "Validation.h"
#include "Person.h"

Employee::Employee(int id=0,string name="",string password="",double salary=5000):Person(id,name,password)
{
    this->salary = Validation::validateSalary(salary);
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
    cout <<"Name: " <<getName() <<endl ;
    cout <<"Password" <<getPassword() <<endl ;
    cout <<"ID: " <<getID() <<endl ;
    cout <<"Salary: " <<getSalary() <<endl;
}
