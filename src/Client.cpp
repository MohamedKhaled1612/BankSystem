#include "Client.h"
Client::Client(int id=0, string name="", string pass="", double balance=1500):Person(id,name,pass)
{
    setBalance(balance);
}

Client::~Client(){}

void Client::setBalance(double balance)
{
    this->balance = Validation::validateBalance(balance) ;
}

double Client::getBalance()
{
    return balance ;
}

void Client::deposit(double amount)
{
    //balance = balance+amount;
    balance+=amount ;
}

void Client::withdraw(double amount)
{
    if(balance<amount)
    {
        cout<<"You can't withdraw this amount\n";
        cout<<"Enter less amount: " ;
        cin>>amount ;
        withdraw(amount);
    }
    else
        balance-=amount ;
}

void Client::transferTo(double amount ,Client& recipient)
{
    /*if(balance-amount <0)
    {
        cout<<"You can't transfer this amount\n";
        cout<<"Enter less amount: " ;
        cin>>amount ;
        transferTo(amount,recipient);
    }
    else
    {
        this->balance-=amount ;
        recipient.balance+=amount ;
    }*/

    this->withdraw(amount) ;
    recipient.deposit(amount) ;
}

void Client::display()
{
    Person::display();
    cout<<"Balance: "<<getBalance()<<endl;
}
