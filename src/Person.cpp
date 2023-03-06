#include "Person.h"
// add default values to implement all
// constructors at once
Person::Person(int ID=0, string N="",string P="")
{
    setID(ID);
    setName(N) ;
    setPassword(P);
}

Person::~Person() {}

//setters
void Person::setID(int id)
{
    this->id = id;
}

void Person::setName(string N)
{
    this->name = Validation::validateName(N);
}

void Person::setPassword(string P)
{
    this->password = Validation::validatePassword(P);
}

//getters
int Person::getID()
{
    return id;
}

string Person::getName()
{
    return name;
}

string Person::getPassword()
{
    return password;
}

void Person::display()
{
    cout <<"Name: " <<getName() <<endl ;
    cout <<"Password: " <<getPassword() <<endl ;
    cout <<"ID: " <<getID() <<endl ;
}
