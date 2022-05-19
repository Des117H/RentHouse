#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
using namespace std;

class User {
    private:

    public:
        User() {};
};

class NonMember : public User
{

};

#endif