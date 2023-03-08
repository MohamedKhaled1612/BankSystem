#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <fstream>
#include <iostream>
#include <vector>
#include "DataSourceInterface.h"
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include <sstream>
using namespace std ;

class FileManager:public DataSourceInterface
{
public:
    FileManager();
    ~FileManager();
    bool exist(int id, string className);
    void addToFile(string,string);
    void addClient(Client);
    void addEmployee(Employee);
    void addAdmin(Admin);
    void removeAllClients() ;
    void removeAllEmployees() ;
    void removeAllAdmins() ;
    vector<Client> getAllClients();
    vector<Employee> getAllEmployees();
    vector<Admin> getAllAdmins();
};

#endif // FILEMANAGER_H
