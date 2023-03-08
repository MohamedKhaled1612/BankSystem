#include "FileManager.h"
const char semicoloumn=';' ;
FileManager::FileManager():DataSourceInterface()
{
    //ctor
}

FileManager::~FileManager()
{
    //dtor
}
bool FileManager::exist(int id,string className)
{

}
void FileManager::addToFile(string file_name,string data)
{
    fstream file(file_name,ios::app) ;
    file<<data<<endl ;
    file.close() ;
}
void FileManager::addClient(Client c)
{
    char semicoloumn=';' ;
    string data=to_string(c.getID())+
    semicoloumn+c.getName()+
    semicoloumn+c.getPassword()+
    semicoloumn+to_string(c.getBalance()) ;
    addToFile("Clients.txt",data) ;
}
void FileManager::addEmployee(Employee e)
{
    string data=to_string(e.getID())+
    semicoloumn+e.getName()+
    semicoloumn+e.getPassword()+
    semicoloumn+to_string(e.getBalance())+
    semicoloumn+to_string(e.getSalary()) ;
    addToFile("Employee.txt",data) ;
}

void FileManager::addAdmin(Admin e)
{
    string data=to_string(e.getID())+
    semicoloumn+e.getName()+
    semicoloumn+e.getPassword()+
    semicoloumn+to_string(e.getBalance())+
    semicoloumn+to_string(e.getSalary()) ;
    addToFile("Admin.txt",data) ;
}
void FileManager::removeAllClients()
{
    fstream file("Clients.txt",ios::out) ;
    file.close() ;
}
void FileManager::removeAllEmployees()
{
    fstream file("Employee.txt",ios::out) ;
    file.close() ;
}
void FileManager::removeAllAdmins()
{
    fstream file("Admin.txt",ios::out) ;
    file.close() ;
}
vector<Client> FileManager::getAllClients()
{
    string line,part;
    vector<Client> allClients ;
    vector<string> line_parts ;
    fstream file_to_read("Clients.txt",ios::in) ;

    while(getline(file_to_read, line))
    {
        stringstream ss(line) ;
        while(getline(ss,part,';'))
            line_parts.push_back(part) ;

        //clear the array of data
        line_parts.clear() ;
        allClients.push_back(Client(stoi(line_parts[0]), line_parts[1],line_parts[2],stod(line_parts[3])));
    }
    file_to_read.close() ;
    return allClients;

}

vector<Employee> FileManager::getAllEmployees()
{
    string line,part;
    vector<Employee> allEmployees ;
    vector<string> line_parts ;
    fstream file_to_read("Employee.txt",ios::in) ;

    while(getline(file_to_read, line))
    {
        stringstream ss(line) ;
        while(getline(ss,part,';'))
            line_parts.push_back(part) ;

        //clear the array of data
        line_parts.clear() ;
        allEmployees.push_back(Employee(stoi(line_parts[0]), line_parts[1],line_parts[2],stod(line_parts[3]),stod(line_parts[4])));
    }
    file_to_read.close() ;
    return allEmployees;

}

vector<Admin> FileManager::getAllAdmins()
{
    string line,part;
    vector<Admin> allAdmins ;
    vector<string> line_parts ;
    fstream file_to_read("Admin.txt",ios::in) ;

    while(getline(file_to_read, line))
    {
        stringstream ss(line) ;
        while(getline(ss,part,';'))
            line_parts.push_back(part) ;

        //clear the array of data
        line_parts.clear() ;
        allAdmins.push_back(Admin(stoi(line_parts[0]), line_parts[1],line_parts[2],stod(line_parts[3]),stod(line_parts[4])));
    }
    file_to_read.close() ;
    return allAdmins;

}
