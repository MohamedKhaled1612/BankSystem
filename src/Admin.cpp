#include "Admin.h"
#include "Employee.h"
#include "FileManager.h"
Admin::Admin():Employee()
{
}
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

void Admin::addEmployee(Employee e)
{
    FileManager().addEmployee(e);
}

Employee Admin::searchEmployee(int id)
{
    //declare string
    string line ;

    //open the file
    fstream file(FileManager().getEmployeeFileName(), ios::in);

    //read data and compare
    while(getline(file,line))
        if(stoi(Parser::split(line)[0])==id)
        {
            vector<string> data(Parser::split(line)) ;
            return Employee(stoi(data[0]), data[1], data[2], stod(data[3]), stod(data[4])) ;
        }
        else return Employee() ;

}

void Admin::listEmployee()
{
    vector<Employee> employees=FileManager().getAllEmployees();
    for(Employee employee: employees)
    {
        cout<<"______________________\n"<<endl;
        employee.display() ;
        cout<<"______________________"<<endl;
        cout<<endl;
    }
}

void Admin::editEmployee(int id,string name, string password, double balance, double salary)
{
    //open file manager
    FileManager fm ;

    //get all employee data to modify
    vector<Employee> all_file_employees = fm.getAllEmployees();

    //check if the old file removed
    remove(fm.getEmployeeFileName().c_str());

    //add Clients again
    for(Employee employee : all_file_employees)
        if(employee.getID()== id)
            fm.addEmployee(Employee(id,name,password,balance,salary));
        else
            fm.addEmployee(employee);
}
