#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using namespace std ;
class Person
{
private:
    int id;
    string name, password;
public:

    //constrcutors
    Person(int id,string name,string password);
    ~Person();

    //setters
    void setID(int) ;
    void setName(string);
    void setPassword(string);

    //getters
    int getID() ;
    string getName() ;
    string getPassword() ;
    void display();

};

#endif // PERSON_H
