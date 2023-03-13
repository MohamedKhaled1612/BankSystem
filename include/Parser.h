#ifndef PARSER_H
#define PARSER_H
#include <sstream>
#include <Client.h>
#include <Employee.h>
#include <Admin.h>
#include <vector>

class Parser
{
public:
    static vector<string> split(string line)
    {
        stringstream stream(line);
        string part;
        vector<string> info;
        while(getline(stream,part,';')) info.push_back(part);
        return info;
    }
    static Client parseToClient(string line)
    {
        vector<string> info=split(line);
        return Client(stoi(info[0]), info[1], info[2], stod(info[3])) ;
    }
    static Employee parseToEmployee(string line)
    {
        vector<string> info=split(line);
        return Employee(stoi(info[0]), info[1], info[2], stod(info[3]), stod(info[4])) ;
    }
    static Admin parseToAdmin(string line)
    {
        vector<string> info=split(line);
        return Admin(stoi(info[0]), info[1], info[2], stod(info[3]), stod(info[4]));
    }

};

#endif // PARSER_H
