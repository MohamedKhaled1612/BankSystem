#ifndef VALIDATION_H
#define VALIDATION_H
#include<iostream>
using namespace std ;
class Validation
{

public:
    Validation();
    virtual ~Validation();

    static bool Alphabetic(string name)
    {
        for(int i=0; i< name.size(); i++)
            if( (name[i]<'A'||name[i]>'Z')&& (name[i]<'a'||name[i]>'z') &&(name[i]!=' ') )
                return false ;

        return true ;
    }

    static string validateName(string name)
    {

        //min 8 max 20 alphabetic
        if(name.size()<5 || name.size()>20 || !Alphabetic(name))
        {
            cout<<"Enter the name again: ";
            //enter the name again
            getline(cin,name) ;
            //recall the function
            validateName(name) ;
        }
        return name;
    }

    static string validatePassword(string password)
    {
        if(password.size()<8 || password.size()>20)
        {
            cout<<"Enter the password again: ";
            //enter the name again
            getline(cin,password) ;
            //recall the function
            validatePassword(password) ;
        }
        return password ;
    }

    static double validateBalance(double balance)
    {
        if (balance<1500)
        {
            cout<<"Enter Balance again: ";
            cin>>balance;
            validateBalance(balance);
        }
        return balance;
    }

    static double validateSalary(double salary)
    {
        if (salary<5000)
        {
            cout<<"Enter Salary again: ";
            cin>>salary;
            validateSalary(salary);
        }
        return salary;
    }
};

#endif // VALIDATION_H
