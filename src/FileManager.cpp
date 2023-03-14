#include "FileManager.h"

FileManager::FileManager():DataSourceInterface()
{
    //ctor
}

FileManager::~FileManager()
{
    //dtor
}

bool FileManager::exist(int id, string fileName)
{
    //define variable line to save line
    string line ;

    //open the file to search
    fstream file(fileName, ios::in);

    //search for id
    while(getline(file,line))
        if(stoi(Parser::split(line)[0])== id) //split the line [id,name,pass,balance] //stoi(id) //compare to id
            return true ;
    return false ;
}

void FileManager::addClient(Client c)
{
    if(exist(c.getID(),client_file_name))
    {
        cout<<"This client id already exist!" ;
        return ;
    }
    fstream file(getClientFileName(),ios::app) ;
    file<<c.getID()<<';'<<c.getName()<<';'<<c.getPassword()<<';'<<c.getBalance()<<endl;
    file.close();
}
void FileManager::addEmployee(Employee e)
{
    if(exist(e.getID(),employee_file_name))
    {
        cout<<"This employee id already exist!" ;
        return ;
    }
    fstream file(getEmployeeFileName(),ios::app) ;
    file<<e.getID()<<';'<<e.getName()<<';'<<e.getPassword()<<';'<<e.getBalance()<<';'<<e.getSalary()<<endl;
    file.close();
}

void FileManager::addAdmin(Admin a)
{
    if(exist(a.getID(),admin_file_name))
    {
        cout<<"This admin id already exist!" ;
        return ;
    }
    fstream file(getAdminFileName(),ios::app) ;
    file<<a.getID()<<';'<<a.getName()<<';'<<a.getPassword()<<';'<<a.getBalance()<<';'<<a.getSalary()<<endl;
    file.close();
}
void FileManager::removeAllClients()
{
    fstream file(getClientFileName(),ios::out) ;
    file.close() ;
}
void FileManager::removeAllEmployees()
{
    fstream file(getEmployeeFileName(),ios::out) ;
    file.close() ;
}
void FileManager::removeAllAdmins()
{
    fstream file(getAdminFileName(),ios::out) ;
    file.close() ;
}

vector<Client> FileManager::getAllClients()
{
    string line ;
    vector<Client> allClients ;
    fstream file_to_read(getClientFileName(),ios::in) ;
    while(getline(file_to_read, line)) allClients.push_back(Parser::parseToClient(line)) ;
    file_to_read.close() ;
    return allClients;
}

vector<Employee> FileManager::getAllEmployees()
{
    string line;
    vector<Employee> allEmployees ;
    fstream file_to_read(getEmployeeFileName(),ios::in) ;
    while(getline(file_to_read, line)) allEmployees.push_back(Parser::parseToEmployee(line)) ;
    file_to_read.close() ;
    return allEmployees;

}

vector<Admin> FileManager::getAllAdmins()
{
    string line;
    vector<Admin> allAdmins ;
    fstream file_to_read(getAdminFileName(),ios::in) ;
    while(getline(file_to_read, line)) allAdmins.push_back(Parser::parseToAdmin(line)) ;
    file_to_read.close() ;
    return allAdmins;

}

string FileManager::getClientFileName()
{
    return client_file_name ;
}

string FileManager::getEmployeeFileName()
{
    return employee_file_name ;
}

string FileManager::getAdminFileName()
{
    return admin_file_name ;
}
