#include "Admin.h"
#include "Employee.h"

Admin::Admin(int id=0,string name="",string password="",double balance=1500,double salary=5000):Employee(id,name,password,balance,salary)
{
}
Admin::~Admin()
{

}

void Admin::display()
{
    Employee::display();

}
