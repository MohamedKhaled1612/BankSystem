#include "FileManager.h"

FileManager::FileManager():DataSourceInterface()
{
    //ctor
}

FileManager::~FileManager()
{
    //dtor
}

void FileManager::addToFile(string file_name,string data)
{
    fstream file(file_name,ios::app) ;
    file<<data<<endl ;
    file.close() ;
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
    //1-preparing string
    string data=to_string(c.getID())+
    semicoloumn+c.getName()+
    semicoloumn+c.getPassword()+
    semicoloumn+to_string(c.getBalance()) ;

    //2-adding to file
    addToFile(client_file_name,data) ;
}
void FileManager::addEmployee(Employee e)
{
    if(exist(e.getID(),employee_file_name))
    {
        cout<<"This employee id already exist!" ;
        return ;
    }
    string data=to_string(e.getID())+
    semicoloumn+e.getName()+
    semicoloumn+e.getPassword()+
    semicoloumn+to_string(e.getBalance())+
    semicoloumn+to_string(e.getSalary()) ;

    addToFile(employee_file_name,data) ;
}

void FileManager::addAdmin(Admin e)
{
    if(exist(e.getID(),admin_file_name))
    {
        cout<<"This admin id already exist!" ;
        return ;
    }
    string data=to_string(e.getID())+
    semicoloumn+e.getName()+
    semicoloumn+e.getPassword()+
    semicoloumn+to_string(e.getBalance())+
    semicoloumn+to_string(e.getSalary()) ;
    addToFile(admin_file_name,data) ;
}
void FileManager::removeAllClients()
{
    fstream file(client_file_name,ios::out) ;
    file.close() ;
}
void FileManager::removeAllEmployees()
{
    fstream file(employee_file_name,ios::out) ;
    file.close() ;
}
void FileManager::removeAllAdmins()
{
    fstream file(admin_file_name,ios::out) ;
    file.close() ;
}

vector<Client> FileManager::getAllClients()
{
    string line ;
    vector<Client> allClients ;
    fstream file_to_read(client_file_name,ios::in) ;
    while(getline(file_to_read, line)) allClients.push_back(Parser::parseToClient(line)) ;
    file_to_read.close() ;
    return allClients;
}

vector<Employee> FileManager::getAllEmployees()
{
    string line;
    vector<Employee> allEmployees ;
    fstream file_to_read(employee_file_name,ios::in) ;
    while(getline(file_to_read, line)) allEmployees.push_back(Parser::parseToEmployee(line)) ;
    file_to_read.close() ;
    return allEmployees;

}

vector<Admin> FileManager::getAllAdmins()
{
    string line;
    vector<Admin> allAdmins ;
    fstream file_to_read(admin_file_name,ios::in) ;
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
