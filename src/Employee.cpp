#include "Employee.h"
#include"FileManager.h"
#include"Parser.h"
Employee::Employee():Client()
{
    setSalary(5000) ;
}
Employee::Employee(int id=0,string name="",string password="",double balance=1500,double salary=5000):Client(id,name,password,balance)
{
    setSalary(salary);
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
    Client::display() ;
    cout<<"Salary: " <<getSalary() <<endl;
}

void Employee::addClient(Client c)
{
    FileManager().addClient(c);
}

Client Employee::searchClient(int id)
{
    //declare string
    string line ;

    //open the file
    fstream file(FileManager().getClientFileName(), ios::in);

    //read data and compare
    while(getline(file,line))
        if(stoi(Parser::split(line)[0])==id)
        {
            vector<string> data(Parser::split(line)) ;
            return Client(stoi(data[0]), data[1], data[2], stod(data[3])) ;
        }
        else return Client() ;

}

void Employee::listClient()
{
    vector<Client> clients=FileManager().getAllClients();
    for(Client client: clients)
    {
        cout<<"______________________\n"<<endl;
        client.display() ;
        cout<<"______________________"<<endl;
        cout<<endl;
    }
}

void Employee::editClient(int id,string name, string password, double balance)
{
    //open file manager
    FileManager fm ;

    //get all clients data to modify
    vector<Client> all_file_clients = fm.getAllClients();

    //check if the old file removed
    remove(fm.getClientFileName().c_str());

    //add Clients again
    for(Client client : all_file_clients)
        if(client.getID()== id)
            fm.addClient(Client(id,name,password,balance));
        else
            fm.addClient(client);
}
