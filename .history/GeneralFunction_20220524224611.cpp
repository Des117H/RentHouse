#include "GeneralFunction.h"

void getData(string path)
{

}

bool login()
{
    bool isValid = false;
    do{
        string username;
        string password;
        cout << "Enter username: ";
        cin >> username;
        for(size_t i = 0; i < members.size(); i++)
        {
            if (username.compare(members[i].getUserName()) == 0)
            {
                isValid = true;
                currentMember = &members[i];
                break;
            }
        }
        if (isValid)
        {
            cout << "Enter your password: ";
            cin >> password;
            if(password.compare(currentMember->getPassword()) == 0)
            {
                cout << "Log in success full!\n";
                return 1;    
            } else
            {
                currentMember = nullptr;
                cout << "Wrong password!";
                return 0;
            }
        } 
        else
        {
            cout << "No user found...";
        } 
    } while(isValid);
}