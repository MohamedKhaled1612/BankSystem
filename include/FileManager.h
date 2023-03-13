#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <iostream>
#include <vector>
#include "DataSourceInterface.h"
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
#include <sstream>
using namespace std ;

class FileManager:public DataSourceInterface
{
    const char semicoloumn=';' ;
    const string client_file_name="Clients.txt";
    const string employee_file_name="Employee.txt";
    const string admin_file_name="Admin.txt";
public:
    FileManager();
    ~FileManager();
    void addToFile(string,string);
    bool exist(int, string) ;
    void addClient(Client);
    void addEmployee(Employee);
    void addAdmin(Admin);
    void removeAllClients() ;
    void removeAllEmployees() ;
    void removeAllAdmins() ;
    vector<Client> getAllClients();
    vector<Employee> getAllEmployees();
    vector<Admin> getAllAdmins();
    string getClientFileName() ;
    string getEmployeeFileName();
    string getAdminFileName() ;
};

#endif // FILEMANAGER_H
