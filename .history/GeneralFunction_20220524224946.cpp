#include "GeneralFunction.h"

void getData(string path)
{

}

bool login()
{
    bool isValid = false;
    do {
        string username;
        string password;
        cout << "Enter username: ";
        cin >> username;
        for (Member member : members)
            if (username.compare(member.getUserName()) == 0)
            {
                isValid = true;
                currentMember = &member;
                break;
            }
        
        if (isValid)
        {
            cout << "Enter your password: ";
            cin >> password;
            if(password.compare(currentMember->getPassword()) == 0)
            {
                cout << "Log in success" << endl;
                return true;    
            }
            else
            {
                currentMember = nullptr;
                cout << "Wrong password!!!" << endl;
                return false;
            }
        } 
        else
            cout << "No user found..." << endl;
    } while(isValid);
}