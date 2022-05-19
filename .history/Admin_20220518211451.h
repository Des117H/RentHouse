#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
using namespace std;

class Admin
{
    private:
        string username;
        string password;
    public:
        Admin();
        Admin(char day, char month, char year);
}
#endif