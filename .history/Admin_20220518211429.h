#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <vector>
using namespace std;

class Admin
{
    private:
        char day;
        char month;
        char year;
    public:
        Date();
        Date(char day, char month, char year);
}
#endif