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
        Admin(string username, string password);
}
#endif