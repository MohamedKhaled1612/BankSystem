#include "Admin.h"
#include "Employee.h"
#include "Validation.h"
#include "Person.h"

Admin::Admin(int id=0,string name="",string password="",double salary=5000):Employee(id,name,password,salary)
{
    this->salary = Validation::validateSalary(salary);
}

Admin::~Admin()
{

}

void Admin::display()
{
    cout <<"Name: " <<getName() <<endl ;
    cout <<"Password" <<getPassword() <<endl ;
    cout <<"ID: " <<getID() <<endl ;
    cout <<"Salary: " <<getSalary() <<endl;
}
