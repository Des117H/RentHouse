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
        if(isValid == 0){
            cout << "Enter your password: ";
            cin >> password;
            if(password.compare(currentMember->getPassword()) == 0){
                cout << "Log in success full!\n";
                return 1;    
            } else{
                currentMember = nullptr;
                cout << "Wrong password!";
                return 0;
            }
        } 
        else{
            cout << "No user found...\n";
            cout << "Do you want to retry? \n";
            cout <<"0. No\n";
            cout <<"1. Yes\n";
            int choice = program->choice();
            if(choice == 0){
                return 0;
            }
        } 
    } while(isValid);
}