#include "Admin.h"

Admin::Admin()
{

}

Admin::Admin(string username, string password)
{
    this->username = username;
    this->password = password;
}

string Admin::getUsername()
{
    return this->username;
}

string Admin::getPassword()
{
    return this->password;
}
