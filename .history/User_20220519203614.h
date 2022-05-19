#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
using namespace std;

class User {
    private:

    public:
        virtual User() {};
};

class NonMember : public User
{
    private:

    public:
        User
};

#endif