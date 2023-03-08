#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include <Client.h>
#include <Employee.h>

class Parser
{
private:
    static vector<string> split(string line){
        stringstream stream(line);
        string x;
        vector<string> info;
        while(getline(stream,x,'&')) info.push_back(x);
        return info;
    }
public:
    static Client parseToClient(string line) {
        vector<string> info=split(line);
        Client client;
        client.setID(stoi(info[0]));
        client.setName(info[1]);
        client.setPassword(info[2]);
        client.setBalance(stod(info[3]));
        return client;
    }
public:
    static Employee parseToEmployee(string line) {
        vector<string> info=split(line);
        Employee employee;
        employee.setID(stoi(info[0]));
        employee.setName(info[1]);
        employee.setPassword(info[2]);
        employee.setSalary(stod(info[3]));
        return employee;

    }
public:
    static Admin parseToAdmin(string line) {
        vector<string> info=split(line);
        Admin admin;
        admin.setID(stoi(info[0]));
        admin.setName(info[1]);
        admin.setPassword(info[2]);
        admin.setSalary(stod(info[3]));
        return admin;

};

#endif // PARSER_H
