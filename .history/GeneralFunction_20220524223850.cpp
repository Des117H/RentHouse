#include "GeneralFunction.h"

void getData(string path)
{

}

bool login()
{
    do{
        string username;
        string pwd;
        cout << "Enter username: ";
        cin >> username;
        for(size_t i = 0; i < program->users.size(); i++){
            if(username == program->users[i].get_userName()){
                is_valid = 0;
                program->CurrentUser = &program->users[i];
            }
        }
        if(is_valid == 0){
            cout << "Enter your password: ";
            cin >> pwd;
            if(pwd == program->CurrentUser->get_pwd()){
                cout << "Log in success full!\n";
                return 1;    
            } else{
                program->CurrentUser = NULL;
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
    } while(is_valid);
}