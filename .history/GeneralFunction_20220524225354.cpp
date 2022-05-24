#include "GeneralFunction.h"

void getData(string path)
{
    fstream file;
    file.open("data.txt", std::ios::in);

    if(!file){
        cout << "Cannot open file!";
        return;
    }

    string data;
    while (!file.eof())
    {   
        getline(file, data);
        if(data.length() == 0) break;
        Member temp;
        inputUserData(temp, inp);
        this->users.push_back(temp);
    }

    file.close();
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
            cout << "Enter password: ";
            cin >> password;
            if(password.compare(currentMember->getPassword()) == 0)
            {
                cout << "Log in success." << endl;
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