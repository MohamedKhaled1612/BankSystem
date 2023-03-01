#include <iostream>
#include "Validation.h"
#include "Client.h"
using namespace std;

int main()
{
    Client c(1,"MMMMMMMMMM","passsssss",3000);
    Client d(1,"MMMMMMMMMM","passsssss",3000);

    c.trasferTo(1000,d) ;

    c.display();
    d.display();
}
