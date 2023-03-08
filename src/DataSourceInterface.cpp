#include "DataSourceInterface.h"

DataSourceInterface::DataSourceInterface()
{
}

DataSourceInterface::~DataSourceInterface()
{
    //dtor
}
virtual void DataSourceInterface::addClient(Client)=0 ;
virtual void DataSourceInterface::addEmployee(Employee) =0;
virtual void DataSourceInterface::addAdmin(Admin)=0;
virtual void DataSourceInterface::removeAllClients()= ;
virtual void DataSourceInterface::removeAllEmployees()=0 ;
virtual void DataSourceInterface::removeAllAdmins()=0 ;
virtual vector<Client> DataSourceInterface::getAllClients()=0 ;
virtual vector<Employee> DataSourceInterface::getAllEmployees()=0 ;
virtual vector<Admin> DataSourceInterface::getAllAdmins()=0 ;
