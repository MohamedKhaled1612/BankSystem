#include <iostream>
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include"FileManager.h"
#include <fstream>
using namespace std;
int main()
{
    FileManager fm;
    fm.removeAllAdmins() ;
    fm.removeAllEmployees() ;
    fm.removeAllClients() ;

}
