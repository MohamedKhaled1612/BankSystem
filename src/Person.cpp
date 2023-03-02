#include "Person.h"
#include "Validation.h"
// add default values to implement all
// constructors at once
Person::Person(int ID=0, string N="",string P="")
{
    id = ID;
    name =Validation::validateName(N) ;
    password = Validation::validatePassword(P);
}

Person::~Person() {}

//setters
void Person::setID(int id)
{
    this ->id = id;
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
